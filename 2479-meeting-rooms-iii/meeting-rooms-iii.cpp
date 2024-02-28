#define ll long long int

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Create a map to keep track of the number of meetings scheduled in each room
        map<int,int> roomCount;

        // Define a lambda function to compare pairs based on their first and second elements
        auto comparator = [] (const pair<ll,int>& a, const pair<ll, int>& b){
            if(a.first == b.first){
                return a.second > b.second;
            } else {
                return a.first > b.first;
            }
        };

        // Define a priority queue of pairs, sorted according to the comparator
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, decltype(comparator)> busyRooms;
        
        // Define a priority queue to keep track of available rooms, sorted in increasing order
        priority_queue<int, vector<int>, greater<int>> freeRooms;

        // Initialize available rooms
        for(int i = 0; i < n ; i++) {
            freeRooms.push(i);
        }

        // Sort the meetings based on their start times
        sort(meetings.begin(), meetings.end());

        // Loop through each meeting
        for(auto &v : meetings) {
            ll start = v[0];
            ll end = v[1];

            // Check if there are any rooms available and if the current meeting can start immediately
            while(!busyRooms.empty() && busyRooms.top().first <= start) {
                // If a room becomes available before the current meeting starts, add it back to freeRooms
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if(!freeRooms.empty()) {
                // If there are available rooms, assign the current meeting to one of them
                roomCount[freeRooms.top()]++;
                busyRooms.push({end, freeRooms.top()});
                freeRooms.pop();
            } else {
                // If there are no available rooms, find the room with the earliest end time and extend its end time
                roomCount[busyRooms.top().second]++;
                auto p = busyRooms.top();
                busyRooms.pop();
                busyRooms.push({p.first + end - start, p.second});
            }
        }

        // Find the room with the maximum number of meetings scheduled
        int maxMeetings = 0;
        int mostBookedRoom = -1;
        for(auto p : roomCount) {
            if(p.second > maxMeetings) {
                maxMeetings = p.second;
                mostBookedRoom = p.first;
            }
        }

        // Return the room number that has the most bookings
        return mostBookedRoom;
    }
};
