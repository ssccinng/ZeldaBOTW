class DTime {
private:
	int day, time;
	void sort() {
		day += time / 24;
		time %= 24;
	}
public:
	int getday() { return day; }
	int gettime() { return time; }
	DTime() {}
	DTime(int day, int time) : day(day), time(time) { sort(); }
	DTime operator + (DTime &x) {
		return DTime(day + x.day, time += x.time);
	}
};