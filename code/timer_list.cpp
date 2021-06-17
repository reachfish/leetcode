#include <list>
#include <memory>

#define SLOT_NUM 3600 * 24 * 7

struct Node {
	uint64_t ts;
	void (*fn)(void*);
	void* arg;
	std::list<std::shared_ptr<Node>>::iterator it;
};

typedef std::shared_ptr<Node> TimerId;

const uint32_t kMaxTaskSize = 1000000;
const TimerId kInvalidTimer{nullptr};

class Timer {
public:
	TimerId Schedule(uint32_t delay, void (*fn)(void*), void* arg) {
		if (task_size_ >= kMaxTaskSize) {
			return kInvalidTimer;
		}

		uint64_t ts = uint64_t(time(nullptr)) + delay;
		auto& slot = slots_[ts % SLOT_NUM];
		auto node = new Node{ts, fn, arg, slot.end()};
		slot.emplace_back(node);
		auto end = slot.end();
		node->it = --end;
		task_size_++;

		return slot.back();
	}

	bool Unschedule(const TimerId& id) {
		if (!id) {
			return false;
		}

		auto& slot = slots_[id->ts % SLOT_NUM];
		if (id->it == slot.end()) {
			return false;
		}

		slot.erase(id->it);
		id->it = slot.end();
		task_size_--;

		return true;
	}

	void Consume() {
		auto now = uint64_t(time(nullptr));
		for (auto ts = last_consume_ts_ + 1; ts <= now; ts++) {
			auto& slot = slots_[ts % SLOT_NUM];
			for (auto it=slot.begin(); it!= slot.end();) {
				auto& node = *it;
				if (node->ts > ts) {
					it++;
				} else {
					(*node->fn)(node->arg);
					node->it = slot.end();
					it = slot.erase(it);
					task_size_--;
				}
			}
		}	

		last_consume_ts_ = now;
	}

private:
	uint64_t last_consume_ts_ = time(nullptr) - 1;
	uint32_t task_size_ = 0;
	std::list<std::shared_ptr<Node>> slots_[SLOT_NUM];
};

int main() {
	return 0;
}
