#include the header file

/*here is some pseudocode to get you started.  You'll have to add other functions as well
  The pseudocode isn't given for all functions */


createList () : pointer-to-a-node
	create a dummy node to be the head of the list
	set the dummy node's next pointer to null
	return the pointer to the dummy node


addFront (pointer-to-a-node head, int )
	newNode <- create a new list element using initElement
	newNode.next  <- head.next
	head.next <- newNode
	
}

printList(pointer-to-a-node head)
{
	currentPosition <- head.next
	loop through the entire linked list (checking for NULL)
		print the value of the current node
		set currenPosition <- current.next
    end loop
    }
}

initNode(int): pointer-to-a-node
{
  	allocate memory for the newNode  (hint, use malloc)
	newNode.nodeValue <- data passed in as the parameter
	newNode.next <- NULL;
	return(newNode);
}
