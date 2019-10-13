
// Написать программу 'библиотека'. Меню консольное, т.е. пользователю 
// предлагается выбрать пункт, с которым он будет работать. Например:
// Введите 1 чтобы вывести все книги
// Введите 2 чтобы внести нового читателя
// И т.д.
// Программа должна уметь
// 1. Выводить доступные в библиотеке книги
// #2. Выводить всех читателей
// # 3. Искать книгу или читателя
// 4. Добавлять книгу
//# 5. Добавлять читателя
// 6. Выдавать и возвращать книгу читателю
// 7. Смотреть какие книги есть у читателя


// файл книга - номер по порядку автор
// файл номер книги и номер пользователя который взял книгу
// файл читатель

// \:\ иванов иван иванович \#\ 1996 \#\ 24.04.1978 \:\n
// book:  author : \:\ иванов А.А. \#\ мастер обьектное проектирование баз данных \#\ 256 стр \#\ 1996 \#\ бхв санкот петеребург \:\n 



//представление файла 
// ## name  / id family name telephone 
// ## book /  id author title little text
// ## taken // author_id books


#include <iostream>
#include <fstream>
#include <string>


using namespace std;

// вывести книги доступные
// внести книгу
// искать книгу
// добавить книгу
// id user_id book_name book_auther book_


class Book {
  std::string sBookAuther;			
  std::string sBookName;
  std::string sBookTitle;  
  int id;
  
public:	const std::string FileBookName = "book.txt";
  
public: int Item(){
		
		std::cout << "Input book" << std::endl;
		std::cout << "# auther " << std::endl;
		std::cout << "# Book name " << std::endl;
		std::cout << "# Boook Title " << std::endl;
		std::cout << "Use space button to divide data" << std::endl;
        std::cin >> sBookAuther >> sBookName >> sBookTitle;
        return 0;
		
	}


public: int getAllBook(){
		
std::cout <<"\n # Get All Book #" << std::endl;	

 	std::fstream fs(FileBookName, std::ios::in | std::ios::out | std::ios::app);
    if(fs.is_open())
    {
		
        while(fs >> id>> sBookAuther >> sBookName >> sBookTitle)
        {
			
			// if book was reseerved then not print it else print it
			
            std::cout << "# id=" << id <<"# Auther  "<< sBookAuther <<" #Book name  "<< sBookName<< " # Book title " << sBookTitle  << std::endl;
        }
            std::cout <<  std::endl;
    }
    fs.close();
	return 0;
}
	
public:	int saveBook(){
	
		std::fstream fs(FileBookName, std::ios::in | std::ios::out | std::ios::app);
    if(fs.is_open())
    {
        std::string tBookAuther, tBookName,tBookTitle;
        std::size_t id(0), found(0);       
               
        while(fs >> id >> tBookAuther >> tBookName >> tBookTitle)
        {
				if(sBookAuther == tBookAuther && sBookName == tBookName && sBookTitle == tBookTitle)
            {
                std::cout << "Book with"<< id << sBookAuther <<" "<< sBookName<<" " << sBookTitle  << "\n"<< std::endl;
                std::cout <<"is exisiting"<< std::endl;
                found = 1;
            }
        }
        if(!found)
        {
            fs.clear();
            fs << '\n' << id + 1 << ' ' << 0 << ' '<< sBookAuther << ' ' << sBookName << ' ' << sBookTitle ;
            std::cout << id + 1 << std::endl;
        }
    }
    else {std::cerr << "Can't open file\n"; fs.close(); return 1;}
    fs.close();
	return 0;
	}	
	
	public: int bookReserved(){
	// make a reservetion book
	return 0;
	
}
	
	
};



// добавить книгу читателю
// удалить книгу от  читателя


class User {
		std::string sName = ""; // имя фамилия отчество
		std::string sSurname = "";
		std::string sFName = "";
		int id=0;
		
	public:	const std::string FileName = "user.txt";
	private: std::string s;
		
// #чтение данных из консоли о пользователе
// #вывод 0 если все успешно
 	
public: int  setUser(){
	
		std::cout << "Input your" << std::endl;
		std::cout << "# name " << std::endl;
		std::cout << "# surname " << std::endl;
		std::cout << "# famaly  " << std::endl;
		std::cout << "Use space button to divide data" << std::endl;
        std::cin >> sName >> sSurname >> sFName;
        return 0;
}
// ############################
// Вывести всех пользователей
// ############################

public: int getAllUser(){
		
std::cout <<"\n # Get All User #" << std::endl;	

 	std::fstream fs(FileName, std::ios::in | std::ios::out | std::ios::app);
    if(fs.is_open())
    {
		
        while(fs >> id>> sName >> sSurname >> sFName)
        {
            std::cout << "# id=" << id <<"# Name  "<< sName <<" #Surname  "<< sSurname<< " #Family " << sFName  << std::endl;
        }
            std::cout <<  std::endl;
    }
    fs.close();
	return 0;
}

public:	int saveUserData(){
	
		std::fstream fs(FileName, std::ios::in | std::ios::out | std::ios::app);
    if(fs.is_open())
    {
        std::string tName, tSurname,tFName;
        std::size_t id(0), found(0);       
               
        while(fs >> id >> tName >> tSurname >> tFName)
        {
				if(sName == tName && sSurname == tSurname && sFName == tFName)
            {
                std::cout << "User with"<< id << sName <<" "<< sSurname<<" " << sFName  << "\n"<< std::endl;
                std::cout <<"is exisiting"<< std::endl;
                found = 1;
            }
        }
        if(!found)
        {
            fs.clear();
            fs << '\n' << id + 1 << ' '<< sName << ' ' << sSurname << ' ' << sFName ;
            std::cout << id + 1 << std::endl;
        }
    }
    else {std::cerr << "Can't open file\n"; fs.close(); return 1;}
    fs.close();
	return 0;
	}	

// результат поиска - число если пользователь существует
// если пользователя нет - результат -1

public: int searchUser(){
		int found = 0;
		std::cout << "Input your" << std::endl;
		std::cout << "# name " << std::endl;
        std::cin >> s;
		
		std::fstream fs(FileName, std::ios::in );
    if(fs.is_open())
    {
		std::string tName, tSurname,tFName;
        while(fs >> id >> tName >> tSurname >> tFName)
        {
			if(s == tName || s == tSurname || s == tFName)
			//if(sName == tName || sSurname == tSurname || sFName == tFName)
            {
                std::cout << "Found   user with #"<< id << " " << sName <<" "<< sSurname<<" " << sFName  << "\n"<< std::endl;
                found = 1;
            }
        }
        if(!found)
        {
            fs.clear();
            std::cout << " User with such a data is not existing" << std::endl;
        }
    }
    else {std::cerr << "Can't open file\n"; fs.close(); return -1;}
    fs.close();
	return 1;
}

// function divider to elementary string

public: void stringDivider(){
	
	std::cout << "enter a name" << std::endl;
	std::cin >> s;
	std::cout << s << std::endl;
	s = "s tt mm";
    std::string delimiter = " ";

size_t pos = 0;
std::string token;
while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    std::cout << token << std::endl;
    s.erase(0, pos + delimiter.length());
}
std::cout << s << std::endl;
}

	
};

class kartoteka {
	// состав файла
	// номер пользователя номер резервированной книги
	//	1 2
	//	1 3
	//	1 4
	
	//	2 5
	//	2 6 
	
	
	
};

int main() {
	
	int k;
	std::string str;
	
	User obj;
	Book objb;

do {
	std::cout << "(1) Info about all user \n";
	std::cout << "(2)Search the book \n";
	std::cout << "(3)Search the user \n";
	std::cout << "(4)Add the book info\n";
	std::cout << "(5)Add the user info\n";
	std::cout << "(6)Reaserved the book to user \n";
	std::cout << "(7)Unreserved the book to user \n";
	std::cout << "(8)Look the information about book that was booked by user \n";
	std::cout << "(9)Quit the pprogramm \n";	
 
std::cout << "make a choise"<< std::endl;
std::cin>> k;	

 	
	
	

switch(k) {
	case 1:{ obj.getAllUser(); break;}
	//case 2: { obj.search.book(); break;}
	case 3: { obj.searchUser(); break;}
	case 4: { objb.Item(); objb.saveBook(); break;}
	case 5: { obj.setUser();obj.saveUserData();break;}
//	case 6: { obj.ReservedBooks(); break;}
//	case 7: { obj.UnReservedBooks(); break;}
//	case 8: { obj.LookUpInfoBook(); break;}
	
}


} while (k!=9);

					
  return 0;


}

