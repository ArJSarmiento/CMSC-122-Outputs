Graph createG1()
{
    char values[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
    Graph g1(values, 8);
    g1.addEdge('A', 'B');
    g1.addEdge('A', 'D');
    g1.addEdge('A', 'G');
    g1.addEdge('B', 'E');
    g1.addEdge('E', 'G');
    g1.addEdge('F', 'D');
    g1.addEdge('F', 'B');
    g1.addEdge('F', 'C');
    g1.addEdge('C', 'H');
    return g1;
}

Graph createG2()
{
    char values[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l' };
    Graph g2(values, 12);
    g2.addEdge('a', 'c');
    g2.addEdge('a', 'd');
    g2.addEdge('a', 'e');
    g2.addEdge('a', 'f');
    g2.addEdge('a', 'k');
    g2.addEdge('c', 'b');
    g2.addEdge('c', 'g');
    g2.addEdge('c', 'd');
    g2.addEdge('d', 'h');
    g2.addEdge('d', 'e');
    g2.addEdge('e', 'i');
    g2.addEdge('f', 'j');
    g2.addEdge('g', 'h');
    g2.addEdge('h', 'i');
    g2.addEdge('i', 'j');
    g2.addEdge('g', 'l');
    g2.addEdge('k', 'l');
    return g2;
}

/*
    This function validates integer inputs. Loops until a valid input is entered.
    Input: pointer of input integer
    Output: none
*/
void input_validation(int &input)
{
    while (!(cin >> input))
    {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(100, '\n');
    }
}

/*
    This function validates string inputs. Gets the entire line of input. 
    Input: pointer of input string
    Output: none
*/
void input_validation_string(string &str)
{
    cin.ignore();
    getline(cin, str);
}

/*
    This function displays the program summary with corresponding input
    Input: none
    Output: none
*/

void summary()
{
    cout <<"\nGraph Traversal Program" 
         <<"\n\t[1] Perform DFS Traversal" 
         <<"\n\t[2] Perform BFS Traversal"
         <<"\n\t[3] Search Item using DFS"
         <<"\n\t[4] Search Item using BFS"
         <<"\n\t[0] Exit"
         << "\nEnter choice: ";
}

Graph graphChoice (Graph g1, Graph g2)
{
    cout << "\nChoose a graph to perform traversal on: "
         << "\n\t[1] Graph 1"
         << "\n\t[2] Graph 2"
         << "\nEnter choice: ";
    int gChoice;
    input_validation(gChoice);
    while (gChoice != 1 && gChoice != 2)
    {
        cout << "Invalid input. Please enter a number: ";
        input_validation(gChoice);
    }
    if (gChoice == 1)
        return g1;
    else
        return g2;
}