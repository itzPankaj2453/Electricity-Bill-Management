#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
    int customer_id;
    float unit, charge, bill, surcharge, rate;
    string name, choice;
    cout << "\n========== MENU ==========" << endl;
    cout << "1.-->> Generate and Save Bill <<--" << endl;
    cout << "2.-->> View Saved Bills <<--" << endl;
    cout << "3.-->> Delete All Saved Records <<--" << endl;
    cout << "4.-->> Exit <<--" << endl;
    do
    {
        cout << "\n-->>Key words : Entry , View , Delete , Exit" << endl;
        cout << "-->>Enter Choice: ";
        cin >> choice;
        cin.ignore(1000,'\n');
        if (choice == "Entry" || choice == "entry")
        {
            surcharge = 0;
            cout << "-->>Enter Your Customer ID: ";
            cin >> customer_id;
            cout << "-->>Enter Your Name: ";
            cin.ignore(1000, '\n');
            getline(cin, name);
            cout << "-->>Enter the number of Units Consumed: ";
            cin >> unit;
            if (unit < 0)
            {
                cout << "-->>Invalid units!<<--" << endl;
                continue;
            }
            else if (unit <= 199)
            {
                rate = 1.20;
                charge = unit * rate;
            }
            else if (unit < 400)
            {
                rate = 1.50;
                charge = unit * rate;
            }
            else if (unit <= 600)
            {
                rate = 1.80;
                charge = unit * rate;
            }
            else
            {
                rate = 2.00;
                charge = unit * rate;
            }
            bill = charge;
            if (bill > 400)
            {
                surcharge = bill * 0.15;
                bill += surcharge;
            }
            if (bill < 100)
            {
                bill = 100;
            }
            cout << "\n->Customer ID : " << customer_id << endl;
            cout << "->Name : " << name << endl;
            cout << "->Units Consumed : " << unit << endl;
            cout << "->Amount Charges @Rs " << rate << " per unit : "
                 << fixed << setprecision(2) << charge << endl;
            cout << "->Surcharge Amount : "
                 << fixed << setprecision(2) << surcharge << endl;
            cout << "->Net Amount Paid By the Customer : "
                 << fixed << setprecision(2) << bill << endl;
            ofstream outfile("Electricity_bill.txt", ios::app);
            if (outfile.is_open())
            {
                outfile << "\nCustomer ID : " << customer_id << endl;
                outfile << "Name : " << name << endl;
                outfile << "Units Consumed : " << unit << endl;
                outfile << "Net Amount Paid : "
                        << fixed << setprecision(2) << bill << endl;
                outfile << "--------------------------------------------------" << endl;
                outfile.close();
                cout << "\n-->>Bill details saved successfully!<<--" << endl;
            }
            else
            {
                cout << "\n!! Error opening file !!" << endl;
            }
        }
        else if (choice == "View" || choice == "view")
        {
            ifstream infile("Electricity_bill.txt");

            if (infile.is_open())
            {
                string line;

                cout << "\n========== SAVED BILLS ==========\n";

                while (getline(infile, line))
                {
                    cout << line << endl;
                }

                infile.close();
            }
            else
            {
                cout << "!No records found or file cannot be opened." << endl;
            }
        }
        else if (choice == "Delete" || choice == "delete")
        {
            char confirm;

            cout << "Are you sure you want to delete all records? (Y/N): ";
            cin >> confirm;
            cin.ignore(1000, '\n');

            if (confirm == 'Y' || confirm == 'y')
            {

                if (remove("Electricity_bill.txt") == 0)
                {

                    cout << "All records deleted successfully!" << endl;
                }
                else
                {
                    cout << "File not found or could not be deleted!" << endl;
                }
            }
            else
            {
                cout << "-->>Deletion cancelled!<<--" << endl;
            }
        }
        else if (choice == "Exit" || choice == "exit")
        {
            cout << "-_-Thank You!-_-" << endl;
        }
        else
        {
            cout << "! Invalid Choice! Please try again !" << endl;
        }

    } while (choice != "Exit" && choice != "exit");

    return 0;
}