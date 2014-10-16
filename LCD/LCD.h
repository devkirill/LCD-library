#ifndef Display_h
#define Display_h

class Display<Type>
{
private:
	Type Width;
	Type Height;
	virtual void Repaint() = 0;
	virtual bool Paint(Type x, Type y) = 0;
public:
	Display(Type width, Type height);
};

#endif