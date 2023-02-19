#include<iostream>
#include<string>

using namespace std;

//global variable 
int Guess ;
int total ;

class Question {
    private :
    string question0;
    string answer1;
    string answer2;
    string answer3;
    string answer4;
    int correct_answer;
    int question_score;

public:
//function prototype declartaion

//setter function
void setvalues (string , string , string , string , string , int , int );

//function to ask question 
void askquestion();

};

int main() {
    cout<<"\n\n\t\t\t\tThe Daily Quiz"<<endl;
    cout<<"\nPress Enter to start the quiz....."<<endl;

    //input 
    cin.get();

    string Name ;
    int age ;

    //input details 
    cout<<"What's your name ?"<<endl;
    cin>>Name ;
    cout<<endl;

    cout<<"How old are you ?"<<endl;
    cin>>age;
    cout<<endl;

    string response;
    cout<<"Are you intrested to take the quiz "
        <<Name << "? yes/no" 
        <<endl;
    cin>>response;

    if (response == "yes"){
        cout<<"\nGood Luck ! "<<endl;
    }
    else {
        cout<<"Okay Good Bye !"<<endl;
        return 0;
    }

    //objects of Question Class 
    Question q1 , q2 ,q3 , q4 , q5 , q6 ,q7 , q8, q9 , q10;

    // 3 is the position of the correct answer 
    //sample format : q2.setvalues("Question : ", "Answer 1","Answer 2","Answer 3","Answer 4", 3 , 10);
    q1.setvalues("Question : How many isotopoes of Hydrogen ? ", "4 ","2","3","1", 3 , 10);
    q2.setvalues("Question : Who is the first person of India ? ", "Mr Kovind ","Mrs Patil","Mr APJ kalam","Mrs Draupadi Murmu", 4 , 10);
    q3.setvalues("Question : How many planet in our solar system ?", "10","9","8","7", 3 , 10);
    q4.setvalues("Question : Which country won the FIFA cup ?", "Russia ","France","Argentina","Brazil", 3 , 10);
    q5.setvalues("Question : Which one is an Indian MNC ", "Ford","Honda","Tata Motors","Mahendra Motors", 3 , 10);
    q6.setvalues("Question : World's Second largest Desert is ", "Savana","Rokies","Thar","Sahara", 3 , 10);
    q7.setvalues("Question : Which country have longest rail-route in the world ?", "Dubai","USA","Russia","Canada", 3 , 10);
    q8.setvalues("Question : How many chromosomes in a human cell ?", "23","22","46","44", 3 , 10);
    q9.setvalues("Question : value of gravity at poles ", "9 N/m^2","9.8 N/m^2","10 N/m^2","10.2 N/m^2", 3 , 10);
    q10.setvalues("Question : unit of Charge : ", "Pascal","Amphere","Column","Fradey", 3 , 10);
    

    q1.askquestion();
    q2.askquestion();
    q3.askquestion();
    q4.askquestion();
    q5.askquestion();
    q6.askquestion();
    q7.askquestion();
    q8.askquestion();
    q9.askquestion();
    q10.askquestion();

    //Display the total score 
    cout<<"Total score = "<<total 
        <<" Out of 100 "<< endl;

    //display the results .
    
    //if the player pass the quiz 
    if(total >= 70){
        cout<<"Congratulation you passed the quiz !"<<endl;

    }
    else {
        cout<<"Alas! you failed the quiz. "<<endl;
        cout<<"Better luck next time. "<<endl;
    }

    return 0;
}

//Function to set the values of Question

void Question :: setvalues(
    string q , string a1 ,
     string  a2 ,string a3 ,
      string a4,
     int ca , int pa)
{
        question0 = q;
        answer1 = a1 ;
        answer2 =a2 ;
        answer3 = a3;
        answer4 = a4;
        correct_answer = ca ;
        question_score = pa ;
}

//function to ask question 
void Question :: askquestion()
{
    cout<<endl;
    //print the Question
    cout<< question0 << endl;
    cout<<"1. "<<answer1 << endl;
    cout<<"2. "<<answer2 << endl;
    cout<<"3. "<<answer3 << endl;
    cout<<"4. "<<answer4 << endl;
    cout<<endl;

    //display the answer
    cout<<"what is your answer ?(in number)"<<endl;
    cin>>Guess;

    //if the answer is correct 
    if ( Guess == correct_answer)
    {
        cout<<"\nCorrect! "<<endl;

        //update the correct score
        total = total + question_score;
        cout<<"Score = "<<question_score <<" out of "
            <<question_score
            <<"!" << endl;

        cout<<endl; 
    } 
    else {
        cout<<"\nWrong ! "<<endl;
        cout<<"Score = 0 "
            <<"out of "
            <<question_score <<"!"
            <<endl;

        cout<<"Correct answer = "
            <<correct_answer <<"."
            <<endl;
        cout<<endl;
    }
}