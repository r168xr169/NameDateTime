#include <string>
#include <fstream>
#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

int main(void) {
	using boost::posix_time::ptime;
	using boost::posix_time::second_clock;
	using namespace boost::gregorian;

	date today = day_clock::local_day();
	ptime now = second_clock::local_time();

	//open file
	std::ofstream ofs;

	//create a new file
	std::string filename = (boost::format("%s_%s.txt")
		% to_iso_string(today) % to_iso_string(now.time_of_day())).str();
	ofs.open(filename);

	//output "[time]: test"
	ofs << to_iso_string(now.time_of_day()) << ": test" << std::endl;

	return 0;
}
