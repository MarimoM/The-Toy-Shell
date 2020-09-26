#include <iostream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
using namespace std;

int main()
{
	readyForInput(" ");
	fs::path previousPath;
	fs::path path = "";

	while (true) {
		readyForInput(path);
		string commandLine = newInput();

		//change directory
		if (commandLine.find("cd"))
		{
			int space = commandLine.find(" ");
			string command = commandLine.substr(0, space);
			string inputPath = commandLine.substr(space);

			if (!path.empty()) {
				previousPath = path;
			}
			path = inputPath;
			readyForInput(path);
			continue;
		}

		//list
		if (commandLine == "list") {
			if (!path.empty) {
				for (const auto& entry : fs::directory_iterator(path))
					std::cout << entry.path() << std::endl;
				continue;
			}
			else {
				cout << "No directory selected, use cd command!";
			}
			continue;
		}

		//leave
		if (commandLine == "leave") {
			path = previousPath;
			continue;
		}

		//stop
		if (commandLine == "stop") {
			break;
		}

		//delete
		int deleteFunk = commandLine.find("delete");
		if (deleteFunk != 0)
		{
			int space = commandLine.find(" ");
			string command = commandLine.substr(0, space);
			string filePath = commandLine.substr(space);
			remove(path);
			continue;
		}

		//create dict
		int createFunk = commandLine.find("create");
		if (createFunk != 0)
		{
			int space = commandLine.find(" ");
			string command = commandLine.substr(0, space);
			string file = commandLine.substr(space);
			fs::create_directories(path.parent_path());
			cout << "Dictionary was created!";
			continue;
		}
		
	}
}

void readyForInput(fs::path path) {
	cout << path;
	cout << ">";
}

string newInput() {
	string commandLine = "";
	getline(cin, commandLine);
	return commandLine;
}