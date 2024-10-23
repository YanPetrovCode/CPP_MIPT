#include "token.h"

void Token_stream::putback(Token t)
{
  if (full)
    error("putback() into a full buffer");

  buffer = t;
  full = true;
}

Token Token_stream::get()
{
  if (full)
  {
    full = false;
    return buffer;
  }

  char ch;
  in >> ch;



    //нужно дописать
  if (!in)
  {
    ch = quit;
  }
    
  switch (ch)
  {
  case '(':
  case ')':
  case '+':
  case '-':
  case '*':
  case '/':
  case '%':
  case ';':
  case '=':
    return Token{ch};


  case '.':
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
  {
    in.putback(ch);
    double val;
    in >> val;
    return Token{number, val};
  }

  default:
    if (isalpha(ch))
    {
      string s;
      s += ch;
      while (in.get(ch) && (isalpha(ch) || isdigit(ch)))
        s = ch;
      in.putback(ch);

      if (s == declkey)
        return Token{let};

      return Token{name, atof(s.c_str()) };
    }
    error("Bad token");
  }
}

void Token_stream::ignore(char c)
{
  if (full && c == buffer.kind)
  {
    full = false;
    return;
  }
  full = false;

  char ch;
  while (in >> ch)
    if (ch == c)
      return;
}
