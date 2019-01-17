#include<iostream>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

unordered_map<string, set<int> > name2id;
unordered_map<string, set<int> > author2id;
unordered_map<string, set<int> > publisher2id;
unordered_map<string, set<int> > y; 
unordered_map<string, set<int> > kw;
int n, q;

void print(set<int> a){
	if(a.size() == 0){
		printf("Not Found\n");
		return;
	}
	set<int>::iterator it;
	for(it = a.begin(); it != a.end(); ++it)
		printf("%07d\n", *it);
}

int main(){
	freopen("data.txt", "r", stdin);
//	ios::sync_with_stdio(false);
	scanf("%d", &n);
	int id;
	string name, author, key, publisher, year;
	for(int i = 0; i < n; ++i){
		scanf("%d", &id);
		getchar();
		getline(cin, name);
		getline(cin, author);
		getline(cin, key);
		getline(cin, publisher);
		getline(cin, year);
		name2id[name].insert(id);
		author2id[author].insert(id);
		publisher2id[publisher].insert(id);
		y[year].insert(id);
		string temp;
		for(int j = 0; j < key.length(); ++j){
			if(key[j] == ' '){
				kw[temp].insert(id);
				temp.clear();
			}else{
				temp += key[j];
			}
		}
		kw[temp].insert(id);
	}
	scanf("%d", &q);
	getchar();
	string query;
	for(int i = 0; i < q; ++i){
		getline(cin, query);
		cout << query << endl;
		int num = query[0] - '0';
		for(int j = 0; j < 3; ++j){
			query.erase(query.begin());
		}
		if(num == 1)	print(name2id[query]);
		else if(num == 2)	print(author2id[query]);
		else if(num == 3)	print(kw[query]);
		else if(num == 4)	print(publisher2id[query]);
		else	print(y[query]);
	}
	return 0;
}
