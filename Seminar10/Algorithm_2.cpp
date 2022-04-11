#include <iostream>
#include <algorithm>
using namespace std;

struct MeetingTime {
	int begintime;
	int endtime;
	MeetingTime(int begintime, int endtime) : begintime(begintime), endtime(endtime){}
};
bool cmb(struct MeetingTime a, struct MeetingTime b)
{
	return a.endtime < b.endtime; 
}
int analysis_meetings(struct MeetingTime arr[], int size)
{
	int number_of_permission_meetings = 1; // first meeting of sort arr all time is permission
	sort(arr, arr + size, cmb);
	int current_endtime = arr[0].endtime; // ending time of current meeting
	for (int i = 0; i < size; i++)
	{
		if (arr[i].begintime > current_endtime) {
			current_endtime = arr[i].endtime;
			number_of_permission_meetings++;
		}
	}
	return number_of_permission_meetings;
}
int main()
{
	MeetingTime Meetingtimelist[] = { {1, 2},{1, 3},{3, 4},{5, 7},{7, 10},{1, 7} };
	int size = sizeof(Meetingtimelist) / sizeof(Meetingtimelist[0]);
	cout << analysis_meetings(Meetingtimelist, size);
	cout << size;
}
