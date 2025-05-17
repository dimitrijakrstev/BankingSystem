# 💳 Banking System (C++)

This is a terminal-based Banking System program written in C++. It allows users to create and manage different types of bank accounts (e.g., savings and checking), perform transactions, and save data using file handling. The project is designed using object-oriented principles and manual memory management.

---

## 🚀 Features

- Create accounts (Savings / Checking)
- Deposit and withdraw funds
- View balance and transaction history
- Overdraft limits for checking accounts
- Interest rates for savings accounts
- File persistence (data is saved between sessions)
- Input validation and exception handling
- Dynamic memory management using `new` / `delete`
- Simple menu-driven interface

---

## 🛠 Technologies Used

- C++ (Object-Oriented Design)
- File I/O (`fstream`)
- Exception handling (`try` / `catch`)
- Dynamic memory management
- Custom Vector implementation (optional)

---

## 📁 Project Structure
/BankingSystem/
├── main.cpp
├── Menu.h / Menu.cpp           # Main interaction handler
├── BankAccount.h / .cpp        # Base account class
├── SavingsAccount.h / .cpp     # Inherits BankAccount
├── CheckingAccount.h / .cpp    # Inherits BankAccount
├── Vector.h / Vector.cpp       # Custom dynamic array (optional)
├── accounts.txt                # File to store account data

---

## 🧪 How to Compile

You can compile using any standard C++ compiler. Example using `g++`:

```bash
g++ main.cpp Menu.cpp BankAccount.cpp SavingsAccount.cpp CheckingAccount.cpp Vector.cpp -o banking
Run it: ./banking
```

---

📌 How It Works
	1.	Run the program and choose from the menu options.
	2.	Create a new account by entering account type and details.
	3.	Deposit or withdraw money with validation.
	4.	All accounts are saved to a file and loaded on startup.
	5.	Supports unlimited accounts and shows a summary when exiting.

---

🧠 Concepts Practiced
	•	Inheritance & Polymorphism
	•	Input validation
	•	File-based data persistence
	•	Exception safety
	•	Resource management
	•	Modular design

---

👨‍💻 Author

Dimitrija Krstev
Computer Engineering Student @ BME
