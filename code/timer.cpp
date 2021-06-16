#include <vector>

struct Node {
	uint64_t ts;
	uint64_t index;
	uint32_t vidx;
	void (*fn)(void*);
	void* arg;

	bool operator<(const Node& other) const {
		return ts < other.ts || (ts==other.ts && index < other.index);
	}
};

struct TimerId {
	uint64_t ts;
	uint64_t index;
	Node* node;
};

const TimerId kInvalidTimer{0, 0, nullptr};

const uint32_t kMaxTimerSize = 10000;

class Timer {
public:
	TimerId Schedule(uint32_t delay, void (*fn)(void*), void* arg) {
		if (tasks_.size() >= kMaxTimerSize) {
			return kInvalidTimer;
		}

		uint64_t ts = uint64_t(time(nullptr)) + delay;
		uint32_t i = tasks_.size();
		auto node = new Node {ts, next_index_++, i, fn, arg};
		tasks_.push_back(node);
		RefreshUp(i);

		return  {node->ts, node->index, node};
	}

	bool Unschedule(const TimerId& id) {
		if (tasks_.empty()) {
			return false;
		}

		auto top = tasks_.front();
		if (top->ts > id.ts || (top->ts == id.ts && top->index > id.index)) {
			return false;
		}

		auto node = id.node;
		node->ts = 0;
		RefreshUp(node->vidx);
		assert(node->vidx == 0 && tasks_.front() == node);
		Pop();
		delete node;

		return true;
	}

	void Consume() {
		while (!tasks_.empty() && tasks_[0]->ts <= time(nullptr)) {
			auto node = Pop();
			(*node->fn)(node->arg);
			delete node;
		}
	}

private:
	Node* Pop() {
		auto top = tasks_.front();
		tasks_[0] = tasks_.back();
		tasks_[0]->vidx = 0;
		tasks_.pop_back();
		RefreshDown(0);
		return top;
	}

	void RefreshUp(uint32_t i) {
		while (i) {
			uint32_t pi = (i-1)/2;
			if (!(*tasks_[i] < *tasks_[pi])) {
				break;
			}
			Swap(i, pi);
			i = pi;
		}
	}

	void RefreshDown(uint32_t i) {
		for (;;) {
			uint32_t left = 2 * i + 1;
			uint32_t right = left + 1;

			uint32_t min_idx = i;
			for (auto k : { left, right }) {
				if (k < tasks_.size() && *tasks_[k] < *tasks_[min_idx]) {
					min_idx = k;
				}
			}

			if (i == min_idx) {
				break;
			}

			Swap(i, min_idx);
			i = min_idx;
		}
	}

	void Swap(int i, int j) {
		std::swap(tasks_[i], tasks_[j]);
		std::swap(tasks_[i]->vidx, tasks_[j]->vidx);
	}

private:
	std::vector<Node*> tasks_;
	uint64_t next_index_ = 1;
};

int main() {
    return 0;
}
