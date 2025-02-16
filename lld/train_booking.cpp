#include <array>
#include <cstddef>
#include <optional>
#include <string>
#include <queue>
#include <sqlite3.h>

using std::optional, std::array, std::string, std::queue;

#define COACH_SIZE 60

enum class BookingStatus {
	WAITING_LIST,
	BOOKED,
	FULL,
};

enum class Berth {
	AC,
	NON_AC,
	SEATER,
};

struct Person {
	string name;
	int age;
	string phone_no;
	// More identification numbers go here
	
	Person(string name, int age, string phone_no) {
		this -> name = name;
		this -> age = age;
		this -> phone_no = phone_no;
	}
};

struct Coach {
	array<optional<Person>, COACH_SIZE> available;
	size_t end = 0;
	queue<Person> waiting;
	Berth type;

	BookingStatus allocate_seat(Person owner) {
		if (end >= available.size()) {
			waiting.push(owner);
			return BookingStatus::WAITING_LIST;
		} else {
			available[end] = owner;
			end += 1;
			return BookingStatus::BOOKED;
		}
	}
};

struct Train {
	std::vector<Coach> coaches;
	int train_no;
	
	Train(int train_no) {
		this -> train_no = train_no;
		this -> coaches = {};
	}

	BookingStatus allocate_seat(const Berth type, const Person& owner) {
		for (auto coach : coaches) {
			if (coach.type == type) {
				BookingStatus res = coach.allocate_seat(owner);
				if (res == BookingStatus::BOOKED) break;
				else continue;
			}
		}
	}

};


int main(void) {
	sqlite3 *db;
	if (sqlite3_open("./train.db", &db) != SQLITE_OK) {
		return 1;
	}
	sqlite3_close(db);
	return 0;
}
