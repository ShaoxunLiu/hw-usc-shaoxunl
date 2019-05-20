#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

bool is_in(std::string x, std::vector<std::string> xs);
int main(int argc, char* argv[]){
    if(argc < 2){
        std::cout << "Not enough arguments." << std::endl;
        return -1;
    }

    std::ifstream tweet;
    tweet.open(argv[1]);
    if (!tweet.is_open()){
        std::cout << "Input file failed to open." << std::endl;
        return -1;
    }

    //creating string vector for input lines
    std::vector<std::string> twLines;
    std::string newline;

    for(std::getline(tweet, newline); !tweet.fail();std::getline(tweet, newline)){
        twLines.push_back(newline);
    }
    
    int tweets = 0;
    std::vector<std::string> users;
    std::vector<std::string> hashtags;

    //input 
    for(int i = 0; i < (signed int)twLines.size(); i++){
        if(twLines[i].length() < 1){
            continue;
        }
        std::vector<std::string> words;
        std::stringstream ss(twLines[i]);
        std::string newword;
        for(ss >> newword; !ss.fail(); ss >> newword){
            words.push_back(newword);
        }
        for(int j = 0; j < (signed int)words.size(); j++){
            std::string init;
            init = words[j].substr(0,1);
            if(init == "#"){
                std::string hashtag = (words[j].substr(1,(words[j].length())));
                if(!is_in(hashtag, hashtags)){
                    hashtags.push_back(hashtag);
                }
            }else if(init == "@"){
                std::string user = (words[j].substr(1,(words[j].length())));
                if(!is_in(user, users)){
                    users.push_back(user);
                }               
            }
        }
        tweets ++;
    }
    
    //out put
    std::cout << "1. Number of tweets=" << tweets << std::endl << "2. Unique users" << std::endl;
    for(int i = 0; i < (signed int)users.size(); i++){
        std::cout << users[i] << std::endl;
    }
    std::cout << "3. Unique hashtags" << std::endl;
    for(int i = 0; i < (signed int)hashtags.size(); i++){
        std::cout << hashtags[i] << std::endl;
    }    


    return 0;
    

}

bool is_in(std::string x, std::vector<std::string> xs){
    for(int i = 0; i < (signed int)xs.size(); i++){
        if(xs[i] == x){
            return true;           
        }
    }
    return false;
}