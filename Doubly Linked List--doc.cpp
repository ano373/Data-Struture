
struct double_linked_list_node
{
	int dd ;
	double_linked_list_node   *prev , *next;
};
class double_linked_list
{
private:
	double_linked_list_node  *first , *last ;
public:
	double_linked_list()	{ first = last = NULL;	}
	bool is_empty(void) { return first == NULL; }
	void insert_first(int data) ;
	void insert_last(int data)	;
	void insert_at_index(int index, int data) ;
	void insert_data_inorder(int data) ;
	int delete_first() ;
	int delete_last() ;
	int delete_index(int index) ;
	int delete_first_data_occur(int data) ;
	int  get_size() ;
	int search(int dd) ;
	void print_first_to_last() ;
	void print_last_to_first() ;
	void delete_list();
};

	void double_linked_list::insert_first(int data)
	{
		struct double_linked_list_node  *temp;
		temp = new double_linked_list_node ;
		temp->dd = data ;
		temp->prev = NULL;
		temp->next = first;
		if(first != NULL)		first->prev = temp;
		first = temp;
		if(last == NULL)	last = temp;
	}
	void double_linked_list::insert_last(int data)
	{
		if(first ==NULL)	{	double_linked_list::insert_first(data) ; return; } 
		struct double_linked_list_node  *temp;
		temp = new double_linked_list_node ;
		temp->dd = data ;
		temp->prev = last;
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
	int double_linked_list::search(int data) 
	{
		struct double_linked_list_node  *temp;
		int k , size , index;
		size = double_linked_list::get_size();
		temp = first;
		index = -1 ;
		k = 1;
		for(temp = first ; temp != NULL ; temp = temp->next) 
		{
			if(temp->dd == data)		{ index = k ;   break; }
			else 	k++;
		}
		if(index == -1)		{ cout << data << " could not be found\n";    return -1 ; }
		else						
		{ cout << data << " is found at index " << index << "\n";    return index ; }
	}
	void double_linked_list::insert_at_index(int index, int data) 
	{
		if(first ==NULL)	 {double_linked_list::insert_first(data) ; return;}
		if(index <= 1)	{ double_linked_list::insert_first(data) ; return;}
		if(index >= double_linked_list::get_size())		
		{ double_linked_list::insert_last(data);  return; }

		struct double_linked_list_node  *before , *after , *temp;
		int k ;

		before = first;
		for(k = 1 ; k < index ; k++)
			before = before->next ;
		after = before->next;
		temp = new double_linked_list_node;
		temp->dd = data;
		temp->prev = before;
		temp->next = after;
		before->next = after->prev = temp;
	}
	void double_linked_list::insert_data_inorder(int data) 
	{
		if(first ==NULL)		
		{ double_linked_list::insert_first(data) ;  return; } 
		if(data < first->dd)		
		{ double_linked_list::insert_first(data) ; return; }
		if(data > last->dd)		
		{ double_linked_list::insert_last(data); return; }

		struct double_linked_list_node  *before , *after , *temp;

		for(after = first ; after->dd < data ;  after = after->next)		
			continue;
			
		before = after->prev;
		temp = new double_linked_list_node;
		temp->dd = data;
		temp->prev = before;
		temp->next = after;
		before->next = after->prev = temp;
	}
	
	int double_linked_list::delete_first() 
	{
		if(first ==NULL)		{cout <<  "Empty Linked List \n"; return -1; }
		struct double_linked_list_node  *temp;
		int data;
		data = first->dd;
		temp = first;
		first = first->next ;
		if(first == NULL)		last = NULL;
		else							first->prev = NULL;
		delete temp;
		return data;
	}
	int double_linked_list::delete_last() 
	{
		if(first ==NULL)		{cout <<  "Empty Linked List \n"; return -1; }
		struct double_linked_list_node  *temp;
		int data;
		data = last->dd;
		temp = last;
		last = last->prev ;
		if(last == NULL)		first = NULL;
		else							last->next = NULL;
		delete temp;
		return data;
	}
	int double_linked_list::delete_index(int index) 
	{
		if(first ==NULL)		{cout <<  "Empty Linked List \n"; return -1; }
		if(index <= 1)		return double_linked_list::delete_first() ;
		if(index >= double_linked_list::get_size())		return double_linked_list::delete_last();

		struct double_linked_list_node  *before , *after , *temp;
		int data , k ;
		temp = first;
		for(k = 1 ; k < index ; k++)
			temp = temp->next ;
		data = temp->dd;
		before = temp->prev;
		after = temp->next;
		before->next = after;
		after->prev = before ;
		delete temp;
		return data;
	}
	int double_linked_list::delete_first_data_occur(int data) 
	{ 
		if(first ==NULL)		{cout <<  "Empty Linked List \n"; return -1; }
		struct double_linked_list_node  *before , *after , *temp;
		int k = 1;
		for(temp = first ; temp != NULL ; temp = temp->next)
			if(temp->dd == data)		 break;
			else								k++;

		if(temp == NULL) 
		{ cout << data << " could not be found\n";    return -1 ; }
		if(temp == first)		return double_linked_list::delete_first();
		if(temp == last)	return double_linked_list::delete_last();
		before = temp->prev;
		after = temp->next;
		before->next = after;
		after->prev = before ;
		delete temp;
		cout << data << " is found at index " << k << " and is deleted\n";
		return k;
	}
	int  double_linked_list::get_size() 
	{
		struct double_linked_list_node  *temp;
		int counter = 0 ;
		for(temp = first ; temp != NULL ; temp = temp->next)			
			counter++;
		return counter ;
	}
	
	void double_linked_list::print_first_to_last() 
	{
		struct double_linked_list_node  *temp;
		for(temp = first ; temp != NULL ; temp = temp->next)
			cout << temp->dd << "\t";
		cout << "\n";
	}

	void double_linked_list::print_last_to_first() 
	{
		struct double_linked_list_node  *temp;
		for(temp = last ; temp != NULL ; temp = temp->prev)
			cout << temp->dd << "\t";
		cout << "\n";
	}

	void double_linked_list::delete_list(void)
	{
	}
	void main(void)
	{
		double_linked_list soso;
		int k ;
		for(k = 1 ; k <= 10 ; k++)
			soso.insert_first(k*k);
		cout << "\n Print First to Last \t";
		soso.print_first_to_last();

		cout << "\n Print Last to First \t";
		soso.print_last_to_first();

		while(!soso.is_empty())
			cout << soso.delete_last() << "\t";
		
		getch(); 
	}



