// C15-Multiple-Inheritance-Person-Artist-Musician.cpp 
#include <iostream>
#include <string>
using namespace std;

// Base class: Person
class Person {
public:
    Person(const string& name, int age) : name(name), age(age) {}

    void displayPersonInfo() const {
        cout << "Person=>   Name: " << name << ", Age: " << age << endl;
    }

protected:
    string name;
    int age;
};

// Base class: Artist (representing artistic skills)
class Artist {
public:
    void performArt() const {
        cout << "Artist=>   Performing artistic expression." << endl;
    }
};

// Derived class: Musician (inherits from Person and Artist)
class Musician : public Person, public Artist {
public:
    Musician(const string& name, int age, const string& instrument)
        : Person(name, age), instrument(instrument) {
    }

    void playInstrument() const {
        cout << "Musician=> " << name << " is playing the " << instrument << "." << endl;
        performArt(); // Use the inherited Artist method
    }

    void displayMusicianInfo() const {
        displayPersonInfo();
        cout << "Musician=> Instrument: " << instrument << endl;
    }

private:
    string instrument;
};

int main() {
    Musician musician("Lisa Simpson", 8, "Saxophone");
    musician.displayMusicianInfo();
    musician.playInstrument();

    return 0;
}