#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class StartOrEnd {
public:
    int time;
    int type;   // 0 for start, 1 for end
    int event_id;   // if start, the id of this event
    StartOrEnd(int time, int type, int event_id) : time(time), type(type), event_id(event_id) {}
};

string schedule_event(vector<StartOrEnd> &events) {
    // sort all events by timestamp
    sort(events.begin(), events.end(), [](const StartOrEnd &lhs, const StartOrEnd &rhs){
        return lhs.time < rhs.time || (lhs.time == rhs.time && lhs.type > rhs.type);
    });
    // for (int i = 0; i < events.size(); ++i)
    //     cout << events[i].time << ", " << events[i].type << endl;

    // always assign to first person if available
    // int event_cnt_ongoing = 0;
    int c = 0, j = 0;
    string ret(events.size() >> 1, 'N');
    for (int i = 0; i < events.size(); ++i) {
        // start
        if (events[i].type == 0) {
            if (c == 0) {
                c = 1;
                ret[events[i].event_id] = 'C';
            } else if (j == 0) {
                j = 1;
                ret[events[i].event_id] = 'J';
            } else {
                return string("IMPOSSIBLE");
            }
        }
        // end
        else {
            if (ret[events[i].event_id] == 'C')
                c = 0;
            else
                j = 0;
        }
    }
    return ret;
}

int main() {
    int t; cin >> t;
    for (int z = 0; z < t; ++z) {
        int n; cin >> n;
        vector<StartOrEnd> events;
        for (int event_id = 0; event_id < n; ++event_id) {
            int start, end;
            cin >> start >> end;
            events.push_back(StartOrEnd(start, 0, event_id));
            events.push_back(StartOrEnd(end, 1, event_id));
        }
        string ret = schedule_event(events);
        printf("Case #%d: %s\n", z + 1, ret.c_str());
    }
}