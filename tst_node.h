#ifndef TSTNODE_H 
#define TSTNODE_H 
#include <string>   
#include <tuple>
class TST_node {  

public:   
	TST_node(); 
	~TST_node();   
	void inc_kleft();  
	void inc_kright();    
	int get_kleft_count();   
	int get_kright_count();   
	std::string get_kleft_word();  
	std::string get_kright_word();   
	bool kleft_status();   
	bool kright_status();       
	void set_mid(TST_node * node); 
	void set_right(TST_node * node); 
	void set_left(TST_node * node);      
  void set_kleft(std::string word);  
  void set_kright(std::string word);     
  void set_kleft_count(int count);   
  void set_kright_count(int count);       
  TST_node * get_mid();    
  TST_node * get_right();  
  TST_node * get_left();       
  std::tuple<std::string, int> get_kleft();  
  std::tuple<std::string, int> get_kright();      
  void deinc_kright();  
  void deinc_kleft();    
  void reset_kleft();    
  void reset_kright();  
  void putin_kleft(std::tuple<std::string , int> temp); 
  void putin_kright(std::tuple<std::string , int> temp);   
  bool complete_empty();    
  void make_bool_right(); 
  void make_bool_left(); 

private:
	std::tuple<std::string , int>  kleft;  
	std::tuple<std::string , int> kright;
	TST_node *left; 
	TST_node *right; 
	TST_node *mid;      
  bool leftempty;   
  bool rightempty;
};


#endif
