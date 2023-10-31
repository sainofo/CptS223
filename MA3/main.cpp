/*
* Nofo Fanene
* 10/14/23
* CptS 223 MA 3
*/

#include <map>
#include "TwitterData.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = {{"rangerPower", "Smith", "Rick", "smithRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"}};
    TwitterData *twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }

    // Your code goes here
    // Map Scenario 1  - UserName
    map<int, string> twitterUsernameDataMap;

    twitterUsernameDataMap[1] = "rangerPower";
    twitterUsernameDataMap[2] = "kittyKat72";
    twitterUsernameDataMap[3] = "lexi5";
    twitterUsernameDataMap[4] = "savage1";
    twitterUsernameDataMap[5] = "smithMan";
    
    int findUser = 4;
    
    if(twitterUsernameDataMap.find(findUser) != twitterUsernameDataMap.end()){
        TwitterData *tweetData;
        cout << "username: " << tweetData->getUserName() << endl;
    }
    cout << endl;

    for(const auto& group : twitterUsernameDataMap){
       int userID = group.first;
       TwitterData* tweetData;

       cout << "UserID: " << userID << "\n" << "Username: " << tweetData->getUserName() << endl;   
    }

    string foundUser = "savage1";
    cin >> foundUser;
    auto FoundUserKey = twitterUsernameDataMap.find(findUser);

    if(FoundUserKey != twitterUsernameDataMap.end()){
        cout << foundUser << "is found in the map.\n associated value: " << FoundUserKey->second << endl;
    }
    else{
        cout << foundUser << "is not found in the map!\n" << endl;
    }

    string RemoveUser = "savage1";
    int deleteUser = 4;
    twitterUsernameDataMap.erase(deleteUser);

    if(twitterUsernameDataMap.find(deleteUser) == twitterUsernameDataMap.end()){
        cout << RemoveUser << "has been removed from the map." << endl;
    }
    else{
        cout << RemoveUser << "is still in the map" << endl;
    }


    // Map Scenario 2 - Email
       map<int, string> twitterEmailDataMap;

       twitterEmailDataMap[1] = "smithRick@gmail.com";
       twitterEmailDataMap[2] = "kat@gmail.com";
       twitterEmailDataMap[3] = "lexi5@gmail.com";
       twitterEmailDataMap[4] = "ksavage@gmail.com";
       twitterEmailDataMap[5] = "rick@hotmail.com";

       int findEmail = 2;

       if(twitterEmailDataMap.find(findEmail) != twitterEmailDataMap.end()){
        TwitterData* tweetData;
        cout << "Email: " << tweetData->getEmail()<< endl;
       }
       cout << endl;

        for(const auto& group : twitterEmailDataMap){
            int UserID = group.first;
            TwitterData* tweetData;
            auto TwitterEmailDataMap = group.second;

            cout << "UserID: " << UserID << "\n" << "Email: " << tweetData->getEmail() << endl;
        }
       
       string foundEmail = "kat@gmail.com";
       auto foundEmailKey = twitterEmailDataMap.find(findEmail);

       if(foundEmailKey != twitterEmailDataMap.end()){
        cout << foundEmail << "is found in the map!\n associated value: " << foundEmailKey->second << endl;
       }
       else{
        cout << foundEmail << "is not found in the map!" << endl;
       }

       string removeEmail = "kat@gmail.com";
       int deleteEmail = 2;
       auto RemoveEmailKey = twitterEmailDataMap.erase(deleteEmail);

       if(twitterEmailDataMap.find(deleteEmail) == twitterEmailDataMap.end()){
        cout << removeEmail << " is already removed from the map!\n" << endl;
       }
       else{
        cout << removeEmail << " has not been removed in the map.\n" << endl;
       }
    return 0;
}
