# Stamping-press

Your task is to create an interface to the Mall Kiosk 3000!TM which is intuitive for a C++ programmer. Specifically, the programmer who uses your code should be able to create a stamped piece of
metal by simply creating an output stream and writing to it. For example:
int main()
{
stampstream s(30,10);
s << "hi th#re planetoid humans" << endrow
<< " how’s all the fish" << row(5) << "one more";
s << row(4) << " two more" << 3.1415;
s << row(8) << "The quick brown fox jumped over the lazy dog’s back.";
s << row(3) << "the end";
return 0;
}
Running the sample code should produce:
bash$ ./a.out
/------------------------------\
|hi th#re planetoid humans |
| how s all the fish |
| |
|the end |
| two more3 1415 |
|one more |
| |
| |
|The quick brown fox jumped ove|
| |
\------------------------------/
Your code should inherit from the C++ standard library stream class hierarchy where appropriate.
