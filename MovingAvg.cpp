#include<iostream>
#include<vector>

using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        element_lst = new vector<int>(0);
        mSize = size;   /* The container size (window size) */
        mResult = 0;
        cout << "list size = " << element_lst->size() << endl;
    }

    double next(int val) {
		int lst_sz = 0;
        int head;
        vector<int>::iterator it;

        element_lst->push_back(val);
		lst_sz = element_lst->size();

        if(lst_sz > mSize) {
            head = *element_lst->begin();
            mResult = mResult - ((double)head / mSize) + ((double)val / mSize);
            element_lst->erase(element_lst->begin());
        }
        else
        {
            mResult = mResult * (lst_sz - 1) / lst_sz + (double)val / lst_sz;
        }

        return mResult;
    }

    void printAllElement() {
        vector<int>::iterator it;

        cout << "Elements in the container: ";

        for(it = element_lst->begin(); it != element_lst->end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    vector<int> *element_lst;
    int mSize;
    double mResult;
};

int main()
{
    int input;

	cout << "Please input the windows size: ";
    cin >> input;
    MovingAverage m_avg(input);

    while(1)
    {
        cin >> input;
		cout << " The average is " << m_avg.next(input) << endl;
        m_avg.printAllElement();
    }
    return 0;
}

