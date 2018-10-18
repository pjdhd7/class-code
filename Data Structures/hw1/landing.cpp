//Name: Peter Dolan    ID: 12410657
//Date: 02/09/2015  Section: A    Instructor: Morales
//File: landing.cpp    Desc: Landing a spaceship
#include<iostream>
using namespace std;

int main()
{
  int number_of_graphs = 0;
  int graphs_processed = 0;
  int rows = 0;
  int columns = 0;
  int row_coord = 0;
  int column_coord = 0;
  int few_flowers = 0;
  int temp_flowers = 0;
  int** graph;
   
  //get total number of graphs, then logic checks
  cin >> number_of_graphs;
  while(graphs_processed < number_of_graphs)
  {
    //gets input for the graph
	cin >> rows;
	cin >> columns;

    graph = new int*[columns];
    for(int i = 0; i < columns; i++)
	  graph[i] = new int[rows];
	
	//Fill the graph
	for(int k = 0; k < columns; k++)
	  for(int i = 0; i < rows; i++)
		cin>>graph[k][i];
		
    //Black Magic
    for(int k = 0; k < columns - 2; k++)
	  for(int i = 0; i < rows - 2; i++)
	  {
	    temp_flowers = graph[k][i] + graph [k][i+1] + graph[k][i+2] 
	                   + graph[k+1][i] + graph[k+1][i+1] + graph[k+1][i+2]
	                   + graph[k+2][i] + graph[k+2][i+1] + graph[k+2][i+2];
	    if(temp_flowers < few_flowers || (k == 0 && i == 0))
		{
		  few_flowers = temp_flowers;
		  column_coord = k;
		  row_coord = i;
		}
	  }
    
    //output result
    cout <<"#"<<graphs_processed<<": ("<<row_coord<<", "<<column_coord
         <<") "<<few_flowers<<endl;
    
    //Delete graph and start anew
	for (int i = 0; i < columns; i++)
	{
      delete []graph[i];	
	}
	delete []graph;
	row_coord = column_coord = rows = columns = few_flowers = temp_flowers = 0;
	graphs_processed++;
  }
  return 0;
}