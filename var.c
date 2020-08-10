#include "var.h"


//TODO adicionar variáveis string
//TODO trabalhar com floats
//TODO add Missing Operand error


// Return the value of a numeric var.
long get_var(char *name){
	if(name[1] == '\0')
		// len of name = 1
		return(var[name[0]-'a'][0]);
	return(var[name[0]-'a'][name[1]-'a']);
}
// Set a value for a var;
long *set_var(char *name, long value){
	//	printf("set_var:%s << %ld",name,value);
	if(name[1] == '\0'){
		var[name[0]-'a'][0] = value;
		return(&var[name[0]-'a'][0]);
	}
	var[name[0] - 'a'][name[1]-'a'] = value;
	//printf("set_var:%ld\n",&var[name[0] - 'a'][name[1]-'a'] );
	return(&var[name[0] - 'a'][name[1]-'a']);
}
long *get_var_pointer(char *name){
//	printf("name(%s)%d\n",name,name[0]);
	if(name[1] == '\0'){
		return(&var[name[0]-'a'][0]);
	}
	if(name[0] == '\0') return(NULL);
	return(&var[name[0] - 'a'][name[1]-'a']);
}
void clear_vars(){
	for(int i = 0 ; i < 26 ; i++)
		for(int j = 0 ; j < 26 ; j ++)
			var[i][j] = 0;
}
// Test if we have a var attibution like  day = 10.
int test_attribution(char *buffer){
	int counter = 0;
	while(buffer[counter] != 0){
		if(buffer[counter] == '=')
			return(TRUE);
		counter++;
	}
	return(FALSE);

}

//TODO set Missing operand error 
long *exec_attribution(char *buffer){
	char var_name[20];
	int size; // size of string read
	sscanf(buffer," %[^=] =%n",var_name,&size);
	if(var_name[1] == ' ') var_name[1] = '\0'; 
//	printf("new var (%s)= %d, left:(%s),%ld\n",var_name,size,buffer+size,evaluate(buffer+size));
	
//	printf("%ld",set_var(var_name,evaluate(buffer+size)));
	return(set_var(var_name,evaluate(buffer+size)));

}

