#pragma once        //ensures that this header file is only included once in a single compilation
#include <iostream>
#include <vector>     //includes the vector library for managing a list of followers
#include <algorithm>  //includes the algorithm library for using the std::remove function

template <typename T> //difine a class template that can work with any data type T
class Twitter {
private:
    T followedUser;    //variable to store the followed user
    std::vector<T> followers; //vector to store the list of followers
    const size_t maxFollowers = 5;  //set maximum of followers to 5

public:
    Twitter(T user) : followedUser(user) {}    //is the constructor that initializes the followedUser with the provided user

    void addFollower(T follower) {             //a function that takes a follower of type T
        if (followers.size() < maxFollowers) {  //checks if the followers list has fewer than 5 followers
            followers.push_back(follower);      //add the follower to the followers list
        } else {
            std::cout << "Follower list is full!" << std::endl;    //print if followers list is full
        }
    }

    void removeFollower(T follower) {             //is a function that takes a follower of type T
        auto it = std::remove(followers.begin(), followers.end(), follower); //finds and moves the follower to the end of the vector.
        if (it != followers.end()) {               //checks if the follower was found
            followers.erase(it, followers.end());  //removes the follower from the followers list.
        } else {
            std::cout << "Follower not found!" << std::endl;  //prints a message if the follower was not found.
        }
        printFollowers();              //calls the printFollowers function to display the updated list of followers.
    }

    void printFollowers() const {       //is a function that prints the list of followers.
        std::cout << "Followers of " << followedUser << ":" << std::endl;   //prints the followed user's name.
        for (const auto& follower : followers) {   //iterates through each follower in the followers list.
            std::cout << follower << std::endl;   //prints each follower.
        }
    }
};
