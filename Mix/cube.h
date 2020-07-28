namespace mycube{

class cube{
	public:
		double getvolume();
		void setlength(double length);
	
	private:
		double length;
};
double cube:: getvolume(){
	
	return length*length*length;
}
void cube:: setlength(double len){
	length = len;
}
}
