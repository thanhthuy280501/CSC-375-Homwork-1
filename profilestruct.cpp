struct Profile {          // Define the profile struct contains fields username, age, and state
    std::string username;
    int age;
    std::string state;

    bool operator==(const Profile& other) const {      //compare profile object
        return username == other.username;
    }

    friend std::ostream& operator<<(std::ostream& os, const Profile& profile) {       //print
        os << "Username: " << profile.username << ", Age: " << profile.age << ", State: " << profile.state;
        return os;
    }
};
