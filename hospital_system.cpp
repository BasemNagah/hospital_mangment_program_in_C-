#include<iostream>
using namespace std;

const int max_speci = 20 ;
const int max_names = 5 ;
int speci_num ;
string copy_name ;
int copy_status ;


int specialization[max_speci+1] = {0} ;
string names[max_speci+1][max_names] ;
int status[max_speci+1][max_names] ;

void add_patient(void) ;

void print_all_patients(void) ;

void Get_next_patient(void) ;


int main() {

    int choice ;
    int exit_flag  = 0 ;
    while(1)
    {
        cout<<"********* Welcome to hospital system *********\n" ;
        cout<<"1) Add new patients\n" ;
        cout<<"2) Print all patients\n" ;
        cout<<"3) Get next patient\n" ;
        cout<<"4) Exit\n" ;
        cout<<"your choice : " ;
        cin>>choice ;

        switch(choice)
        {
        case 1:
            add_patient() ;
            break ;

        case 2 :
            print_all_patients() ;
            break;

        case 3 :
            Get_next_patient();
            break;

        case 4 :
            exit_flag = 1 ;
            break;

        default :
            cout<<"Wrong choice please try again" ;
            break ;
        }

        if(exit_flag == 1)
        {
            cout<<"********* logout successfully ! *********" ;
            break ;
        }

    }


	return 0;
}

void add_patient(void)
{
    cout<<"Enter specialization number : " ;
    cin>>speci_num ;
    if(speci_num>=0 && speci_num<=20)
    {
        cout<<"Enter Name : " ;
        cin>>copy_name ;
        cout<<"Enter status : " ;
        cin>>copy_status ;
        if(specialization[speci_num] < 5)
        {
            //regular
            if(copy_status ==0 )
            {
                names[speci_num][specialization[speci_num]] = copy_name ;
                status[speci_num][specialization[speci_num]] = copy_status ;
                specialization[speci_num]++ ;
                cout<<copy_name<<" added successfully !\n" ;
            }
            else //urgent
            {
                for(int i=specialization[speci_num] ; i>0 ; i--)
                {
                    names[speci_num][i] = names[speci_num][i-1] ;
                    status[speci_num][i] = status[speci_num][i-1] ;
                }

                names[speci_num][0] = copy_name ;
                status[speci_num][0] = copy_status ;
                specialization[speci_num]++ ;
                cout<<copy_name<<" added successfully !\n" ;
            }

        }
        else
        {
            cout<<"Sorry specialization "<<speci_num<<" is full \n" ;
        }
    }
    else
    {
        cout<<"Sorry wrong specialization\n" ;
    }


}

void print_all_patients(void)
{
    for(int i=0 ;i<max_speci ; i++)
    {
        if(specialization[i] !=0)
        {
            cout<<"there are "<<specialization[i]<<" patients in specialization "<<i<<"\n" ;
            for(int j=0 ;j<specialization[i];j++)
            {
                cout<<names[i][j]<<" ";
                if(status[i][j] == 1)
                    cout<<"(urgent)\n" ;
                else
                    cout<<"(regular)\n" ;
            }
            speci_num = -1  ;
        }

    }
    if(speci_num != -1)
        cout<<"No patients \n" ;
}

void Get_next_patient(void)
{
    cout<<"Please enter specialization : ";
    cin>>speci_num ;
    if(speci_num>=0 && speci_num<=20)
    {
        if(!specialization[speci_num])
        {
            cout<<"No patients at the moment. Have rest ,Dr\n" ;
        }
        else
        {
            cout<<names[speci_num][0]<<" please go with the Dr \n" ;
            for(int i=0 ;i<(specialization[speci_num]-1) ; i++)
            {
                names[speci_num][i] = names[speci_num][i+1] ;
                status[speci_num][i] = status[speci_num][i+1] ;
            }

            specialization[speci_num]-- ;

        }
    }



}
