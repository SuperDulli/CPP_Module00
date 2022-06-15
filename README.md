# CPP_Module00
basics of C++ - megaphone, PhoneBook and Account

## ex00: Megaphone

a program that converts its arguments into all upercase

usage:
`./megaphone [msg-list]`
examples:
```
$>./megaphone "shhhhh... I think the students are asleep...
"SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *$>
```

## ex01: My Awesome PhoneBook

It can store a maximum of 8 contacts. If the user tries to add a 9th contact,replace the oldest one by the new one.
The user can input ADD, SEARCH or EXIT to add new contacts, display the information or exit the programm and delete the entire PhoneBook.

## ex02: The Job Of YourDreams

The task was to recreate the behaviour (i.e. implement the lost file Account.cpp) that could be observed in the log file and make the tests work.

check with `make compare`
- downloads logfile from intra
- removes the timestamp from the logs
- compares the two logs
