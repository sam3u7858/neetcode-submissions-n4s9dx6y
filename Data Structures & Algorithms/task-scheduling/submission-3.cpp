class Solution {
public:
    struct Task {
        int freq;
        char tag;
        bool operator<(const Task& other) const {
            return freq < other.freq; // max heap
        }
    };

    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks) {
            freq[c - 'A']++;
        }

        priority_queue<Task> pq;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                pq.push({freq[i], static_cast<char>('A' + i)});
            }
        }

        int time = 0;
        queue<pair<Task, int>> cooldown; // (Task, available_time)

        while (!pq.empty() || !cooldown.empty()) {
            time++;

            // 任務 cooldown 完成後重新加入 pq
            if (!cooldown.empty() && cooldown.front().second == time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }

            if (!pq.empty()) {
                Task t = pq.top(); pq.pop();
                t.freq--;
                if (t.freq > 0) {
                    cooldown.push({t, time + n + 1});
                }
            }
        }

        return time;
    }
};
