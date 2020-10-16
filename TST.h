#ifndef TST_H   
#define TST_H  
# include <string>      
#include "tst_node.h"
class TST{        

public:   
	TST();   
	~TST();     
  TST_node * insert(std::string word, TST_node * node);   
  TST_node * gethead();      
  std::tuple<std::string , int> search(std::string word, TST_node * node);   
  void inorder(TST_node * node);    
  void range_search(TST_node* node, std::string smallword, std::string bigword);     
  void postorder_destroy(TST_node * node);   
  void delete_key(TST_node *node, std::string word);  
  std::tuple<std::string , int> find_max(TST_node* node);  
  std::tuple<std::string , int> find_min(TST_node* node);    
  void delink(TST_node * node, TST_node * head);     
private:
	TST_node * head;   	
};

#endif
