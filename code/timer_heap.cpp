#include <vector>
#include <memory>

struct Node {
	uint64_t ts;
	uint32_t index;
	void (*fn)(void*);
	void* arg;
	bool valid;

	bool operator<(const Node& other) const {
		return ts < other.ts || (ts==other.ts && uint64_t(intptr_t(this)) < uint64_t(intptr_t(&other)));
	}
};


typedef std::shared_ptr<Node> TimerId;

const TimerId kInvalidTimer{nullptr};

const uint32_t kMaxTimerSize = 10000;

class Timer {
public:
	TimerId Schedule(uint32_t delay, void (*fn)(void*), void* arg) {
		if (tasks_.size() >= kMaxTimerSize) {
			return kInvalidTimer;
		}

		uint64_t ts = uint64_t(time(nullptr)) + delay;
		uint32_t i = tasks_.size();
		auto node = new Node {ts, i, fn, arg, true};
		tasks_.emplace_back(node);
		RefreshUp(i);

		return tasks_[node->index];
	}

	bool Unschedule(const TimerId& id) {
		if (!id || !id->valid) {
			return false;
		}

		auto node = id.get();
		node->ts = 0;
		RefreshUp(node->index);
		assert(node->index == 0 && tasks_.front().get() == node);
		Pop();

		return true;
	}

	void Consume() {
		while (!tasks_.empty() && tasks_[0]->ts <= time(nullptr)) {
			auto node = Pop();
			(*node->fn)(node->arg);
		}
	}

private:
	TimerId Pop() {
		auto top = tasks_.front();
		top->valid = false;
		tasks_[0] = tasks_.back();
		tasks_[0]->index = 0;
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
		std::swap(tasks_[i]->index, tasks_[j]->index);
	}

private:
	std::vector<std::shared_ptr<Node>> tasks_;
};

int main() {
    return 0;
}
