#include <iostream>

using namespace std;
    
  void check_balance(int balance)
    {
        cout<<"Your balance is 1000 ghc "<< balance;
    }


// Function for resetting/changing the user pin
    void reset_pin(int& pin) {
        int new_pin;
        cout << "Enter new pin: ";
        cin >> new_pin;
        pin = new_pin;
        cout << "Pin has been updated to: " << pin << endl;
    }



// Function for sending money to another account
    void send_money(int& balance) {
        int amount;
        cout << "Enter amount: ";
        cin >> amount;
        if (amount <= balance) {
            balance -= amount;
            cout << "You have sent " << amount << " to the receiver. Your new balance is " << balance << endl;
        }
        else {
            cout << "Not enough balance." << endl;
        }
    }

  // Function for exiting the program
    void exit_program() {
        cout << "Thanks for using CLIFFORD'S MOBILE MONEY SERVICE. Goodbye!" << endl;
        exit(0);
    }


  // Function for authenticating the user
    bool authenticate(int remaining_attempts,int user_pin, int default_pin){
        cout << "Enter your pin: ";
        cin >>user_pin;
        if (user_pin == default_pin) {
            return true;
        }
        else {
            remaining_attempts--;
            if (remaining_attempts == 0) {
                cout << "Maximum number of attempts reached. Goodbye!" << endl;
                exit(1);
                }
            else {
                cout << "Incorrect user_pin. You have " << remaining_attempts << " attempts left." << endl;
                return false;
    }
  }
}

int main()
{
    // declaring variables
    int option;
    int remaining_attempts = 3;
    int user_pin;int balance;
	int default_pin = 0000;
    int default_balance = 1000;

    //Greeting message
    cout << "WELCOME TO CLIFFORD'S MOBILE MONEY SERVICE\n";

    //Left a space to separate greeting message from the rest
    cout <<"\n";

    // Writing a code to display various options
    //i.e: Listing the features of the program
    while (true){
    cout<<"Please select an option\n";
    cout<<"1.Check balance\n";
    cout << "2. Send Money\n";
    cout << "3. Reset/Change Pin\n";
    cout << "4. Exit\n";
    cout << "Enter your option please ";

    //Taking user input
    cin >> option;

	switch(option) {
      case 1:
        if (authenticate(remaining_attempts,user_pin,default_pin)) {
          check_balance(balance);
        }
        break;
      case 2:
        if (authenticate(remaining_attempts,user_pin,default_pin)) {
          send_money(balance);
        }
        break;
      case 3:
        if (authenticate(remaining_attempts,user_pin,default_pin)) {
          reset_pin(default_pin);
        }
        break;
      case 4:
        exit_program();
      default:
        cout << "Invalid choice. Please select a valid option." << endl;
        break;
    }
  }
  return (0);
}



