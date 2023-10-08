#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

const int stringAmount = 10;
string inputStrings[stringAmount];
int characters[stringAmount];
string page, line, tag_name;
int task;

string find_first_element(const string &xml, const string &tag_name)
{
    string start_tag = "<" + tag_name + ">";
    string end_tag = "</" + tag_name + ">";

    size_t start_pos = xml.find(start_tag);
    if (start_pos == string::npos)
    {
        return "Tag not found";
    }

    start_pos += start_tag.length();

    size_t end_pos = xml.find(end_tag, start_pos);
    if (end_pos == string::npos)
    {
        return "End tag not found";
    }

    return xml.substr(start_pos, end_pos - start_pos);
}

vector<string> find_all_elements(const string &xml, const string &tag_name)
{
    vector<string> elements;
    size_t start_pos = 0;

    while (true)
    {
        string result = find_first_element(xml.substr(start_pos), tag_name);

        if (result == "Tag not found")
        {
            break;
        }
        else if (result == "End tag not found")
        {
            break;
        }
        else
        {
            size_t result_pos = xml.find(result, start_pos);
            elements.push_back(result);
            start_pos = result_pos + result.length();
        }
    }
    return elements;
}

int main()
{
    cout << "Choose task to run:\n1. String calculator\n2. Find element in XML.\n0. Exit\n";
    cin >> task;

    switch (task)
    {
    case 1:
        cout << "Enter ten strings\n";
        for (int i = 0; i < stringAmount; i++)
        {
            cout << "Enter string " << i + 1 << ": ";
            cin >> inputStrings[i];
            characters[i] = inputStrings[i].size();
        }
        cout << "You entered the following strings, each with the specified number of characters: \n";
        for (int j = 0; j < stringAmount; j++)
        {
            cout << "String " << j + 1 << ": '" << inputStrings[j] << "' with " << characters[j] << " characters.\n";
        }
        break;

    case 2:
    {
        ifstream inputFile("day-ahead-prices.xml");
        if (!inputFile.is_open())
        {
            cout << "Error: Unable to open the XML file." << endl;
            return 1;
        }
        stringstream buffer;
        buffer << inputFile.rdbuf();
        string xmlContent = buffer.str();

        while (true)
        {
            int subTask;
            cout << "Choose subtask:\n1. Find first element\n2. Find all elements\n";
            cin >> subTask;
            switch (subTask)
            {
            case 1:
                cout << "Enter the tag name to find (or 'stop' to exit): ";
                cin >> tag_name;

                if (tag_name == "stop" || tag_name == "STOP")
                {
                    break;
                }
                else
                {
                    string result = find_first_element(xmlContent, tag_name);

                    if (result.find("not found") != string::npos)
                    {
                        cout << "Tag '" << tag_name << "' not found in the XML." << endl;
                    }
                    else
                    {
                        cout << "Result for tag '" << tag_name << "': " << result << endl;
                    }
                }
                break;
                
            case 2:
                cout << "Enter the tag name to find all occurances of (or 'stop' to exit): ";
                cin >> tag_name;

                if (tag_name == "stop" || tag_name == "STOP")
                {
                    break;
                }
                else
                {
                    vector<string> results = find_all_elements(xmlContent, tag_name);

                    if (results.size() == 0)
                    {
                        cout << "Tag '" << tag_name << "' not found in the XML." << endl;
                    }
                    else
                    {
                        cout << "Results for tag '" << tag_name << "': " << endl;
                        for (int i = 0; i < results.size(); i++)
                        {
                            cout << results[i] << endl;
                        }
                    }
                }
                break;

            default:
                break;
            }
        }
    }
    break;

    case 0:
        return 0;

    default:
        cout << "Invalid choice." << endl;
        break;
    }
    return 0;
}