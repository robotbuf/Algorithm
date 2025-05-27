#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int p, m;

struct Room {
    int lv; // 기준 레벨
    vector<pair<int, string>> people;

    bool isFull() const {
        return people.size() >= m;
    }

    bool canJoin(int newLv) const {
        return abs(lv - newLv) <= 10;
    }

    void addPerson(int lv, const string& id) {
        people.push_back({lv, id});
    }
};

vector<Room> rooms;

int main() {
    cin >> p >> m;

    for (int i = 0; i < p; i++) {
        int lv;
        string id;
        cin >> lv >> id;

        bool joined = false;

        for (auto& room : rooms) {
            if (!room.isFull() && room.canJoin(lv)) {
                room.addPerson(lv, id);
                joined = true;
                break;
            }
        }

        if (!joined) {
            Room newRoom;
            newRoom.lv = lv;
            newRoom.addPerson(lv, id);
            rooms.push_back(newRoom);
        }
    }

    for (auto& room : rooms) {
        if (room.isFull()) {
            cout << "Started!" << endl;
        } else {
            cout << "Waiting!" << endl;
        }

        sort(room.people.begin(), room.people.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });

        for (auto& [lv, id] : room.people) {
            cout << lv << ' ' << id << endl;
        }
    }

    return 0;
}
