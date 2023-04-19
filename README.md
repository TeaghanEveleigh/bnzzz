The following project is a replication of the BNZ banking app with all its essential features for the most part
I implememnt a file management system that stores the user object in a file and then stores the users position in a seperate file in the form of a hashmap the idea generally is to read the hashmap which then will retrieve the user instance upon startup.When we make any transaction we would also update the users transactions in the file and then retrieve the reciever and update their history and ammout.
if this app was to be scaled we would need to create multiple files and have multiple hashmaps that would point to different files and their corresponding position which could be done with relative ease aand this makes the project very scalable for if we were to have a high user count

the user has the following options
1)view balance
2)view transaction history(this shows the users last ten transactions and removes the oldest if it creeps over this amount this can be changed to a larger number if need be)
3) make a transaction where the user asks for the username and then the amount they also have the option to add that user to their quick play list if they have not been added
4)view quick play list this shows the user the quick play list in which they can view their quick pay friends and send money to them on the fly
5)view account info
6)exit the app


PLEASE NOTE//I still plan on adding some form of file encryption likely with bcrypt in order to protect the users information 
Also note that the same concept of reading the file can be done in binary but so that the person viewing this project can see what is happening in the file itself I have made it just text however binary would work just as well the same concept would apply// binary would naturally make this even more scalable and read and write times would improve


