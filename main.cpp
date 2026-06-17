#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int customer_id;
    float unit, charge, bill, surcharge;
    string name, choice;

    cout << "\n========== MENU ==========" << endl;
    cout << "1. Generate and Save Bill" << endl;
    cout << "2. View Saved Bills" << endl;
    cout << "3. Delete All Saved Records" << endl;
    cout << "4. Exit" << endl;

    do
    {
        cout << "\nKey words : Entry , View , Delete , Exit" << endl;
        cout << "Enter Choice: ";

        cin >> choice;
        cin.ignore();

        if (choice == "Entry" || choice == "entry")
        {
            surcharge = 0;

            cout << "\nEnter Your Customer ID: ";
            cin >> customer_id;

            cout << "Enter Your Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter the number of Units Consumed: ";
            cin >> unit;

            cout << "\nCustomer ID : " << customer_id << endl;
            cout << "Name : " << name << endl;
            cout << "Units Consumed : " << unit << endl;

            if (unit <= 199)
            {
                charge = unit * 1.20;
                cout << "Amount Charges @Rs 1.20 per unit : "
                     << fixed << setprecision(2) << charge << endl;
            }
            else if (unit >= 200 && unit < 400)
            {
                charge = unit * 1.50;
                cout << "Amount Charges @Rs 1.50 per unit : "
                     << fixed << setprecision(2) << charge << endl;
            }
            else if (unit >= 400 && unit <= 600)
            {
                charge = unit * 1.80;
                cout << "Amount Charges @Rs 1.80 per unit : "
                     << fixed << setprecision(2) << charge << endl;
            }
            else
            {
                charge = unit * 2.00;
                cout << "Amount Charges @Rs 2.00 per unit : "
                     << fixed << setprecision(2) << charge << endl;
            }

            bill = charge;

            if (bill > 400)
            {
                surcharge = bill * 0.15;
                bill += surcharge;

                cout << "Surcharge Amount : "
                     << fixed << setprecision(2) << surcharge << endl;
            }

            if (bill < 100)
            {
                bill = 100;
            }

            cout << "Net Amount Paid By the Customer : "
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

                cout << "\nBill details saved successfully!" << endl;
            }
            else
            {
                cout << "\nError opening file!" << endl;
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
                cout << "No records found or file cannot be opened." << endl;
            }
        }
        else if (choice == "Delete" || choice == "delete")
        {
            char confirm;

            cout << "Are you sure you want to delete all records? (Y/N): ";
            cin >> confirm;
            cin.ignore();

            if (confirm == 'Y' || confirm == 'y')
            {
                ofstream outfile("Electricity_bill.txt");

                if (outfile.is_open())
                {
                    outfile.close();
                    cout << "All records deleted successfully!" << endl;
                }
                else
                {
                    cout << "Error opening file!" << endl;
                }
            }
            else
            {
                cout << "Deletion cancelled!" << endl;
            }
        }
        else if (choice == "Exit" || choice == "exit")
        {
            cout << "Thank You!" << endl;
        }
        else
        {
            cout << "Invalid Choice! Please try again." << endl;
        }

    } while (choice != "Exit" && choice != "exit");

    return 0;
}