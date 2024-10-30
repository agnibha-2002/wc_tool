#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<fstream>

void countBytes(std::string &filename){
	std::ifstream file(filename,std::ios::binary);

	if(!file){
		std::cerr<<"Error: There is no file present";
		exit(1);
	}

	file.seekg(0,std::ios::end);
	std::streamsize byteCount = file.tellg();
	file.close();

	std::cout<<byteCount<<" "<<filename<<std::endl;

}

void countLines(std::string &filename){
	std::ifstream file(filename,std::ios::binary);

        if(!file){
                std::cerr<<"Error: There is no file present";
                exit(1);
        }

	std::string line;
	int linecount = 0;

	while(std::getline(file,line)){
		linecount++;
	}
	std::cout << "Line Count: " << linecount << std::endl;

        file.close();
}

void countWords(std::string &filename){
	std::ifstream file(filename,std::ios::binary);

	if(!file){
		std::cerr<<"Error: There is no file present";
	}

	std::string word;
        int cnt = 0;
	while(file>>word){
		cnt++;
	}
	std::cout << "Word Count: " << cnt << std::endl;

	file.close();
}

void countChar(std::string &filename){
	std::ifstream file(filename,std::ios::binary);

	if(!file){
		std::cerr<<"Error: There is no file present";
	}
	std::locale::global(std::locale(""));

	char ch;
	int char_cnt = 0;

	while(file.get(ch)){
		char_cnt++;
	}
	
	std::cout << "Character Count: "<<char_cnt<<std::endl;

	file.close();
}

int main(int argc, char* argv[]){

    // If no options are provided, use the first argument as filename
    std::string filename;
    if (argc == 2) {
        filename = argv[1];
    } else if (argc == 3) {
        std::string option = argv[1];
        filename = argv[2];

        if (option == "-c") {
            countBytes(filename);
            return 0;
        } else if (option == "-l") {
            countLines(filename);
            return 0;
        } else if (option == "-w") {
            countWords(filename);
            return 0;
        } else if (option == "-m") {
            countChar(filename);
            return 0;
        } else {
            std::cerr << "Invalid option. Use -c for bytes, -l for lines, -w for words, or -m for characters." << std::endl;
            return 1;
        }
    } else {
        std::cerr << "Usage: " << argv[0] << " -c|-l|-w|-m <filename>" << std::endl;
        return 1;
    }

    // Output results in the required format
    countBytes(filename);
    countLines(filename);
    countWords(filename);
    countChar(filename);


    return 0;
}

