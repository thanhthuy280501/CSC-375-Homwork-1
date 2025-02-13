#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class Twitter {
private:
    T followedUser;
    std::vector<T> followers;
    const size_t maxFollowers = 5;

public:
    Twitter(T user) : followedUser(user) {}

    void addFollower(T follower) {
        if (followers.size() < maxFollowers) {
            followers.push_back(follower);
        } else {
            std::cout << "Follower list is full!" << std::endl;
        }
    }

    void removeFollower(T follower) {
        auto it = std::remove(followers.begin(), followers.end(), follower);
        if (it != followers.end()) {
            followers.erase(it, followers.end());
        } else {
            std::cout << "Follower not found!" << std::endl;
        }
        printFollowers();
    }

    void printFollowers() const {
        std::cout << "Followers of " << followedUser << ":" << std::endl;
        for (const auto& follower : followers) {
            std::cout << follower << std::endl;
        }
    }
};
