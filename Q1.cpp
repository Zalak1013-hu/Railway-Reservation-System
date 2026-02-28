#include <iostream>
#include <string>
using namespace std;

class Train
{
private:
    int trainNumber;
    string trainName;
    string source;
    string destination;
    string trainTime;

public:
    Train()
    {
        trainNumber = 0;
        trainName = "";
        source = "";
        destination = "";
        trainTime = "";
    }

    Train(int number, string name, string src, string dest, string time)
    {
        trainNumber = number;
        trainName = name;
        source = src;
        destination = dest;
        trainTime = time;
    }

    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name: ";
        getline(cin, trainName);

        cout << "Enter Source: ";
        getline(cin, source);

        cout << "Enter Destination: ";
        getline(cin, destination);

        cout << "Enter Train Time: ";
        getline(cin, trainTime);
    }

    void displayTrainDetails()
    {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }

    int getTrainNumber()
    {
        return trainNumber;
    }
};

class TrainSystem
{
private:
    Train trains[100];
    int totalTrains;

public:
    TrainSystem()
    {
        totalTrains = 0;
    }

    void addTrain()
    {
        cout <<endl<<"Enter details for Train " << totalTrains + 1 << ":"<<endl;
        trains[totalTrains].inputTrainDetails();
        totalTrains++;
    }

    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "No train records available!"<<endl;
            return;
        }

        for (int i = 0; i < totalTrains; i++)
        {
            cout <<endl<<"Train " << i + 1 << " details:"<<endl;
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number)
    {
        bool found = false;

        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout <<endl<<"Train Found!"<<endl;
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Train with number " << number << " not found!"<<endl;
        }
    }
};

int main()
{
    TrainSystem tsystem;
    int choice;

    cout << "Enter at least 3 train records initially:"<<endl;
    for (int i = 0; i < 3; i++)
    {
        tsystem.addTrain();
    }

    do
    {
        cout << "--- Train Reservation System Menu ---"<<endl;
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            tsystem.addTrain();
            break;

        case 2:
            tsystem.displayAllTrains();
            break;

        case 3:
        {
            int num;
            cout << "Enter Train Number to search: ";
            cin >> num;
            tsystem.searchTrainByNumber(num);
            break;
        }

        case 4:
            cout << "Exiting the system. Goodbye!"<<endl;
            break;

        default:
            cout << "Invalid choice! Try again."<<endl;
        }

    } while (choice != 4);

    return 0;
}
