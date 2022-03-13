class String {
public:
  String():mp_resource(nullptr), m_length(0) {}  // default Ctr
  
  String (const char * pArg) {  // parameterised ctor
    m_length = strlen(pArg);
    mp_resource = new char[m_length + 1U];
    strcpy(mp_resource, pArg);
  }
  
  String (const String & rArg) {  // copy ctor
     m_length =  rArg.m_length;
     mp_resource = new char[m_length + 1U];
     strcpy(mp_resource, rArg.mp_resource);
  }
  
    String (const String && rArg) {  // move constructor   && rvalue ref
     m_length =  rArg.m_length;
     mp_resource = rArg;
     rArg = nullptr;
     rArg.m_length = 0;
  }
  
 
  String & operator = (const String & rArg ){ // copy assignment operator
    if(this != &rArg){
      delete[] mp_resource;
      m_length = rArg.m_length;
      mp_resource = new char[m_length + 1U];
      strcpy(mp_resource, rArg.mp_resource);
    }
    return *this;
  }
  
  // better copy assignment operator
    String & operator = (const String & rArg ){ // copy assignment operator
    if(this != &rArg){
      char *pTemp = this->mp_resource;
      
      delete[] mp_resource;
      m_length = rArg.m_length;
      mp_resource = new char[m_length + 1U];
      strcpy(mp_resource, rArg.mp_resource);
      
      delete[] pTemp;
    }
    return *this;
  }
  
    //Even better copy assignment operator using CAS idiom (copy and swap idiom)
    String & operator = ( String  rArg ){ // copy assignment operator
    if(this != &rArg){
      Swap(this, rArg);
    }
    return *this;
  }
  void Swap(String & str1, String & str2){
    std::swap(str1.mp_resource, str2.mp_resource);
    std::swap(str1.m_length, str2.m_length);
    
  }
    
  uint8_t length(){ return m_length}
  friend ostream& operator << (ostream& out, const String & rStr);
  friend istream& operator >> (istream& in, const String & rStr);
private:
  uint8_t m_length;
  char * mp_resource;  

};

ostream& operator << (ostream& out, const String & rStr){
out <<  rStr.mp_resource ;
  return out; // to make a chain
}

istream& operator >> (istream& in, const String & rStr){
in >>  rStr.mp_resource ;
  return out; // to make a chain
}

int main(){
  String str1; //default Ctr
  String str2 = "hello"; // parameterised ctor
  String str3 = str1 // copy ctor
  String str5(str1) // copy ctor
  str3 = str2; // copy assignment operator   // handle str3 = str3 (invalid case)
  int len  = str3.length();
  
  cout << str2 << str3; // overload <<
  cin >> str1; // overload >>
  
  String str6 = std::move(str2); // move constructor - handover str2  to str6 , and free str2
  

}
