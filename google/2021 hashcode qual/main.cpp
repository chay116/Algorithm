#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <fstream>

using namespace std;

typedef struct	s_Skill {
	string	name;
	int		level;
}				t_Skill;

typedef struct	s_Project {
	int best;
	int days;
	int score;
	vector<t_Skill> skill;
}				t_Project;

typedef struct	s_Contributor {
	vector<t_Skill> skill;
}				t_Contributor;

typedef struct contributer_table {
	string name;
	string skill;
	int level;
	int day;
}	Table;

vector<Table> contributerTable;
unordered_map<string, t_Project> projects;
unordered_map<string, vector<string> > pools;

string query_SkillLevel(string inSkill, int inLevel, int inDay)
{
	//vector<string> outVec;

	for (auto data : contributerTable) {
			if (data.skill == inSkill && data.level >= inLevel && data.day <= inDay)
				return data.name;
		}
		//return outVec;
		return "";
}

void query_LevelUp(string inName, string inSkill, int level)
{
	for (auto &data : contributerTable) {
		if (data.name == inName && data.skill == inSkill && level >= data.level) {
			++data.level;
		}
	}
}

int main() {
	ofstream writeFile;
	writeFile.open("output.txt");
	int C, P, skill_num, skill_level; string name, skill;
	cin >> C >> P;
	for (int i = 0; i < C; i++) {
		cin >> name >> skill_num;
		for (int j = 0; j < skill_num; j++) {
			cin >> skill >> skill_level;
			contributerTable.push_back({name, skill, skill_level, 0});
		}
	}

	int days, score, best; t_Project tmp_project;
	for (int i = 0; i < P; i++) {
		vector<t_Skill> skill_list;
		cin >> name >> days >> score >> best >> skill_num;
		tmp_project.days = days; tmp_project.score = score;	tmp_project.best = best;
		for (int j = 0; j < skill_num; j++) {
			cin >> skill >> skill_level;
			skill_list.push_back({skill, skill_level});
		}
		tmp_project.skill = skill_list;
		projects.insert(make_pair(name, tmp_project));
	}

	days = 0;
	int project_counter = 0;
	vector<string> answer;
	while (days < 10000 && projects.size()) {
		for (auto i = projects.begin(); i != projects.end(); i++) {
			vector<pair<string, t_Skill> > allocList;
			bool flag = true;
			for (auto requ : i->second.skill) {
				string name = query_SkillLevel(requ.name, requ.level, days);
				t_Skill x{requ.name, requ.level};
				if(name != "")
					allocList.push_back(make_pair(name, x));
				else{
					flag = false;
					break;
				}
			}

			if (flag) {
				project_counter++;
				answer.push_back(i->first);
				answer.push_back("\n");
				for(auto nameStr: allocList)
				{
					query_LevelUp(nameStr.first, nameStr.second.name, nameStr.second.level);
					answer.push_back(nameStr.first);
					answer.push_back(" ");
				}
				answer.push_back("\n");
				projects.erase(i->first);
				break;
			}
		}
		++days;
	}
	writeFile << project_counter << endl;
	for (auto string : answer) {
		writeFile << string;
	}
	writeFile.close();
}