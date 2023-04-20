=# BNZ Banking App Replica

This project is a replication of the BNZ banking app with all its essential features. The app implements a file management system that stores user objects in files and stores users' positions in separate files in the form of a hashmap. The main idea is to read the hashmap upon startup, which retrieves the user instances.

When making any transactions, the app updates the users' transactions in the file and retrieves the receiver to update their transaction history and amount. To scale this app for a high user count, you can create multiple files and have multiple hashmaps pointing to different files and their corresponding positions.

## Features

The user has the following options:

1. **View balance**: Check the current account balance.
2. **View transaction history**: Shows the user's last ten transactions and removes the oldest if it exceeds this amount. This limit can be changed to a larger number if needed.
3. **Make a transaction**: The user inputs the username and the amount for the transaction. The user also has the option to add the recipient to their Quick Pay list if they have not been added.
4. **View Quick Pay list**: Displays the user's Quick Pay list, where they can view their Quick Pay friends and send money to them on the fly.
5. **View account info**: Shows the user's account information.
6. **Exit the app**: Allows the user to exit the app.

## Future Improvements

- Implement some form of file encryption, likely with bcrypt, to protect users' information.
- Note that the same concept of reading the file can be done in binary, but for the sake of this project's readability, the current implementation uses text. Switching to binary would improve scalability and read/write times.
- Increase the number of transactions the user is allowed to view in their history.
- Display the date and time of each transaction in the transaction history.
- Show the account creation date in the account information.
- Allow users to create new accounts to transfer their own money to and name them.

