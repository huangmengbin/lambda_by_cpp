#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define elif else if

const string left_parenthesis = "(left parenthesis)";
const string right_parenthesis = "(right parenthesis)";
const string lambda = "--lambda";
const string abstraction = "[abs]";
const string application = "[app]";
const string isend = "isend";
const string help = "\n"\
"һ����3��ģʽ,Ĭ��Ϊgetline,��ͨ������set������\n"\
"\n"\
"	getlineģʽ��\tÿ��ִ��һ��B��Լ\n"\
"	processģʽ��\tִ�����е�B��Լ,����ʾ�������\n"\
"	finalģʽ:  \tִ�����е�B��Լ,����ʾ�������\n"\
"\n"\
"getlineģʽ�У�����tree,token,lambda�ɷֱ��ӡ֮\n"\
"	����a��\t���������ӽ���a��Լ,��ѡ���Ƿ񱣴�\n"\
"	����step�س�,������������ k��\t���̽���k��B��Լ\n"\
"	����total��\t�鿴�Ѿ������˶��ٲ�\n"\
"	����cal��\t�鿴���ŵ�����\n"\
"	����process��final��\t����ʱ��������Ӧģʽ\n"\
"	����out��\tֱ�ӷ��ص�������̨\n"\
"\n"\
"����ģʽ����𰸺�,����tree,token,lambda,total,cal,out����ִ����Ӧ����\n"\
"	��������2�λس�,Ҳ���Է�����������̨\n"\
"\n"\
"������̨������back��history,�ɲ鿴���һ����ʷ\n"\
"	����set,�л���ͬ��ģʽ\n"\
"	����func,����check���ú���,����define�Լ��ĺ���,����delete�����µ��Ǹ�����\n"\
"	����quit��exit,�˳�����,�뿪bug\n"\
"\n"\
"\n"\
"//���ϵ��ʾ������ִ�Сд";

const vector<string>alphabet = {
"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
"aa","ab","ac","ad","ae","af","ag","ah","ai","aj","ak","al","am","an","ao","ap","aq","ar","as","at","au","av","aw","ax","ay","az",
"ba","bb","bc","bd","be","bf","bg","bh","bi","bj","bk","bl","bm","bn","bo","bp","bq","br","bs","bt","bu","bv","bw","bx","by","bz",
"ca","cb","cc","cd","ce","cf","cg","ch","ci","cj","ck","cl","cm","cn","co","cp","cq","cr","cs","ct","cu","cv","cw","cx","cy","cz",
"da","db","dc","dd","de","df","dg","dh","di","dj","dk","dl","dm","dn","do","dp","dq","dr","ds","dt","du","dv","dw","dx","dy","dz",
"ea","eb","ec","ed","ee","ef","eg","eh","ei","ej","ek","el","em","en","eo","ep","eq","er","es","et","eu","ev","ew","ex","ey","ez",
"fa","fb","fc","fd","fe","ff","fg","fh","fi","fj","fk","fl","fm","fn","fo","fp","fq","fr","fs","ft","fu","fv","fw","fx","fy","fz",
"ga","gb","gc","gd","ge","gf","gg","gh","gi","gj","gk","gl","gm","gn","go","gp","gq","gr","gs","gt","gu","gv","gw","gx","gy","gz",
"ha","hb","hc","hd","he","hf","hg","hh","hi","hj","hk","hl","hm","hn","ho","hp","hq","hr","hs","ht","hu","hv","hw","hx","hy","hz",
"ia","ib","ic","id","ie","if","ig","ih","ii","ij","ik","il","im","in","io","ip","iq","ir","is","it","iu","iv","iw","ix","iy","iz",
"ja","jb","jc","jd","je","jf","jg","jh","ji","jj","jk","jl","jm","jn","jo","jp","jq","jr","js","jt","ju","jv","jw","jx","jy","jz",
"ka","kb","kc","kd","ke","kf","kg","kh","ki","kj","kk","kl","km","kn","ko","kp","kq","kr","ks","kt","ku","kv","kw","kx","ky","kz",
"la","lb","lc","ld","le","lf","lg","lh","li","lj","lk","ll","lm","ln","lo","lp","lq","lr","ls","lt","lu","lv","lw","lx","ly","lz",
"ma","mb","mc","md","me","mf","mg","mh","mi","mj","mk","ml","mm","mn","mo","mp","mq","mr","ms","mt","mu","mv","mw","mx","my","mz",
"na","nb","nc","nd","ne","nf","ng","nh","ni","nj","nk","nl","nm","nn","no","np","nq","nr","ns","nt","nu","nv","nw","nx","ny","nz",
"oa","ob","oc","od","oe","of","og","oh","oi","oj","ok","ol","om","on","oo","op","oq","or","os","ot","ou","ov","ow","ox","oy","oz",
"pa","pb","pc","pd","pe","pf","pg","ph","pi","pj","pk","pl","pm","pn","po","pp","pq","pr","ps","pt","pu","pv","pw","px","py","pz",
"qa","qb","qc","qd","qe","qf","qg","qh","qi","qj","qk","ql","qm","qn","qo","qp","qq","qr","qs","qt","qu","qv","qw","qx","qy","qz",
"ra","rb","rc","rd","re","rf","rg","rh","ri","rj","rk","rl","rm","rn","ro","rp","rq","rr","rs","rt","ru","rv","rw","rx","ry","rz",
"sa","sb","sc","sd","se","sf","sg","sh","si","sj","sk","sl","sm","sn","so","sp","sq","sr","ss","st","su","sv","sw","sx","sy","sz",
"ta","tb","tc","td","te","tf","tg","th","ti","tj","tk","tl","tm","tn","to","tp","tq","tr","ts","tt","tu","tv","tw","tx","ty","tz",
"ua","ub","uc","ud","ue","uf","ug","uh","ui","uj","uk","ul","um","un","uo","up","uq","ur","us","ut","uu","uv","uw","ux","uy","uz",
"va","vb","vc","vd","ve","vf","vg","vh","vi","vj","vk","vl","vm","vn","vo","vp","vq","vr","vs","vt","vu","vv","vw","vx","vy","vz",
"wa","wb","wc","wd","we","wf","wg","wh","wi","wj","wk","wl","wm","wn","wo","wp","wq","wr","ws","wt","wu","wv","ww","wx","wy","wz",
"xa","xb","xc","xd","xe","xf","xg","xh","xi","xj","xk","xl","xm","xn","xo","xp","xq","xr","xs","xt","xu","xv","xw","xx","xy","xz",
"ya","yb","yc","yd","ye","yf","yg","yh","yi","yj","yk","yl","ym","yn","yo","yp","yq","yr","ys","yt","yu","yv","yw","yx","yy","yz",
"za","zb","zc","zd","ze","zf","zg","zh","zi","zj","zk","zl","zm","zn","zo","zp","zq","zr","zs","zt","zu","zv","zw","zx","zy","zz",
};


//һЩ����û�õĺ���
bool   inline is_in(string str, vector<string>stringlist) {
	bool has_it = false;
	for (string temp : stringlist) {
		if (temp == str) {
			has_it = true;
			break;
		}
	}
	return has_it;
}
string inline string_replace(string&s1, const string&s2, const string&s3)
{
	string::size_type pos = 0;
	string::size_type a = s2.size();
	string::size_type b = s3.size();
	while ((pos = s1.find(s2, pos)) != string::npos)
	{
		s1.replace(pos, a, s3);
		pos += b;
	}
	return s1;
}
string inline to_lower_string(string s) {
	s = string_replace(s, "Q", "q");
	s = string_replace(s, "W", "w");
	s = string_replace(s, "E", "e");
	s = string_replace(s, "R", "r");
	s = string_replace(s, "T", "t");
	s = string_replace(s, "Y", "y");
	s = string_replace(s, "U", "u");
	s = string_replace(s, "I", "i");
	s = string_replace(s, "O", "o");
	s = string_replace(s, "P", "p");
	s = string_replace(s, "A", "a");
	s = string_replace(s, "S", "s");
	s = string_replace(s, "D", "d");
	s = string_replace(s, "F", "f");
	s = string_replace(s, "G", "g");
	s = string_replace(s, "H", "h");
	s = string_replace(s, "J", "j");
	s = string_replace(s, "K", "k");
	s = string_replace(s, "L", "l");
	s = string_replace(s, "Z", "z");
	s = string_replace(s, "X", "x");
	s = string_replace(s, "C", "c");
	s = string_replace(s, "V", "v");
	s = string_replace(s, "B", "b");
	s = string_replace(s, "N", "n");
	s = string_replace(s, "M", "m");

	return s;
}
//
//

class mydictionary {
private:
	static vector<string>key_value; 
public:
	static void function_define(string key,string value) {
		key_value.push_back(key);
		key_value.push_back(value);
	}
	static void remove() {
		if (key_value.size() > 86) {//protected number
			key_value.pop_back();
			key_value.pop_back();
			cout << "Success!" << endl << endl;
		}
		else {
			cout << "It can not be deleted." << endl << endl;
		}
	}
	static void check() {
		for (unsigned i = 0; i < key_value.size(); i += 2) {
			if (key_value[i] == "SIXSEVEN") {
				cout<<key_value[i]<< "  <-->\t" << key_value[i + 1] << endl;
			}
			else {
				cout << key_value[i] << "\t  <-->\t" << key_value[i + 1] << endl;
			}
		}
		cout << endl;
	}
	static string replace(string s) {
		for (int i = key_value.size() - 2; i >= 0; i -= 2) {
			s = string_replace(s,key_value[i], key_value[i + 1]);
		}
		return s;
	}
};
//
//<-------------------------------------------------------------------------------AST_Tree
class Tree {//<-------------------------------------------------------------------AST_Tree
private:

	static vector<string>token;					//����������ַ���ת��������������������Ϣ�����е� new Tree ���� new ��������ʽ
	static unsigned Token_ptr;//=0
	void to_token(bool should_clear = true);		//���ݵ�ǰ�������� token ת�ɴ�����Ӧ����ȫ��ʽ


	static void input_token(string s);			//
	static void calculate();
	static void add_parenthesis();//��token��һ������,���˶���

	
	Tree* left_son;// = 0;
	Tree* right_son;// = 0;
	Tree* father;// = 0;
	string attribute;// = "";
	string left_attribute;// = "";
	string right_attribute;// = "";

	


	//�����Ϊ���ӵ�B��Լ-----------------------------------------------------B----------------------------------------
	static vector<string>temp_string_list;
	static vector<string>conflict_symbol_list;//�ұ�Ǳ�ڳ�ͻ�Ŀ��ܵ�����Ԫ��ֻ�ǿ��ܳ�ͻ����
	static vector<string>searched_symbol_list;//���еĲ��ñ���µı������Ķ���

	bool find_conflict_before_B(bool init = true);
	void a_solve_conflict_before_B(string symbol_old, string symbol_new_new, bool shoule_solve_conflict = false);
	void B_replace_to_subtree(string symbol_old, bool init = true);
	void B_replace_to_string(string symbol_old, string symbol_new, bool init = true);
	void point_to_left_and_right_before_B();
	void goto_left_and_delete_right_before_B();
	
	//B��Լ���£�
	bool B_change(bool has_changed = false);//����has changed,��ʾ�Ƿ�ı��˶���-------------------------------------------



public:
	static void output_token();//��ӡtoken? �ðɣ�������parser?
	static void output_lambda();//��ӡ�Ǹ�lambda���ʽ
	static void a_change_token();//a��Լ


	//���ݵ�ǰ�� token (��֧����ȫ��ʽ) ����� , ������һ��������Ӧ�� �﷨��
	Tree(Tree* father = NULL, bool init = true);

	//��������е���������գ������С�ģ�����
	~Tree();


	void print_Tree();			//��������ȱ���.��ӡ��
	static bool check_token_right(string s);//�����û�������Ƿ�Ϸ�
	//<---------------------------------------------------------------------------------------����--------------------------------




	

	//<----------------------------------------------------------------------------------------��ʼ��-------------------
	static bool initial(string s) {
		bool _67nb;
		s=mydictionary::replace(s);
		_67nb = check_token_right(s);
		if (!_67nb) { return _67nb; }

		token.clear();
		input_token(s);
		add_parenthesis();

		return _67nb;
	}
	
	//<-----------------------------------------------------------------------------------------������----------------------------
	static void work(Tree*hmb,string mode) {//<-------------------------------------------------work----------------------------

		string want_to_do = "";
		bool should_continue = false;
		int step = 0;
		unsigned total_step = 0;

		do {
			if (mode == "process" || mode == "getline") {
				hmb->to_token();
				cout << "lambda-> ";
				output_lambda();
				cout << endl;
			}

			step--;//<----------------------------------------------------------------------�����������

			while (mode == "getline"&&step<=0){//�Ǹ��µ�while,----getline
				hmb->to_token();
				cout << "What's your next thought?" << endl;
				getline(cin,want_to_do);
				want_to_do = to_lower_string(want_to_do);
				if (want_to_do == "tree") {
					cout << endl << "Tree: "<< endl << endl;
					hmb->print_Tree();
					continue;
				}
				elif(want_to_do == "token") {
					cout << endl << "token:" << endl << endl;
					hmb->output_token();
					continue;
				}
				elif(want_to_do == "lambda") {
					cout << endl << "lambda:" << endl << endl;
					cout << "lambda-> ";
					hmb->output_lambda();
					continue;
				}
				elif(want_to_do == "total") {
					cout << "total step=" << total_step << endl << endl;
				}
				elif(want_to_do == "cal") {
					calculate();
				}
				elif(want_to_do == "step") {
					cout << "step=";
					int tempstep;
					cin >> tempstep;
					string unuseful;
					getline(cin, unuseful);//<-----------------------------------------Ϊ�˰Ѻ�������ͷ�Ǹ�""��ȥ��������������������
					if (tempstep > 0) {
						step = tempstep;
					}
					else {
						cout << "wrong number" << endl<<endl;
						step = 0;
						continue;
					}
				}
				elif(want_to_do == "a") {
					cout << "a change:" << endl;
					a_change_token();
					cout << "lambda-> ";
					output_lambda();
					cout <<endl<< "Save it or not?" << endl;
					string temp;
					getline(cin, temp);
					temp = to_lower_string(temp);
					if (temp == "yes"||temp=="y") {
						hmb->~Tree();
						hmb = new Tree();
						cout << "Saved��" << endl<<endl;
					}
					elif(temp == "no"||temp=="n") {
						hmb->to_token();
						cout << "Unsaved��" << endl<<endl;
					}
					else {	//������yes
						hmb->~Tree();
						hmb = new Tree();
						cout << "Saved��" << endl<<endl;
					}
				}
				elif(want_to_do == "process") {
					mode = "process";
					cout << endl << "Success!" << endl<<endl;
					continue;
				}
				elif(want_to_do == "final") {
					mode = "final";
					cout << endl << "Success!" << endl << endl;
					continue;
				}
				elif(want_to_do == "out") {
					cout <<endl<< "Success!" << endl << endl;
					return;
				}
				elif(want_to_do == "lambda") {
					cout << endl << "lambda:" << endl << endl;
					cout << "lambda-> ";
					hmb->output_lambda();
					continue;
				}
				elif(want_to_do == "") {//<-------------------------------------break��
					break;
				}
				else {
					cout << "Unrecognized" <<endl<< endl;
					continue;
				}
			} //end getline


			//a_change_token();//-----------------------------������B��Լ֮ǰ����a��Լ

			//hmb->~Tree();//
			//hmb = new Tree();//

			should_continue=hmb->B_change();//<-------------------------����B��Լ

			//hmb->to_token();//-----------------------------������B��Լ֮ǰ����a��Լ
			

			if (hmb->left_son != 0 && hmb->right_attribute == isend) {//������Ϊ��ɾ��һ�����Ŷ���
				hmb->left_son->to_token();
				hmb->~Tree();
				hmb = new Tree();
			}

			total_step++;
		} while (should_continue);

		cout << "lambda->:";
		hmb->to_token();
		output_lambda();
		cout << "\nThat's the answer.\n"<<endl;
//<-------------------------------------------------------------------------------------����....״̬��
		int stop_time = 2;
		do {
			cout << "....";
			getline(cin, want_to_do);
			want_to_do = to_lower_string(want_to_do);
			if (want_to_do == "tree") {
				cout << endl << "Tree: " <<endl<< endl;
				hmb->print_Tree();
				continue;
			}
			elif(want_to_do == "token") {
				cout << endl << "token:" << endl<<endl;
				hmb->output_token();
				continue;
			}
			elif(want_to_do == "cal") {
				calculate();
			}
			elif(want_to_do == "out") {
				break;
			}
			elif(want_to_do=="total") {
				cout << "total step=" << total_step-1 << endl << endl;
			}
			elif(want_to_do == "lambda") {
				cout << "lambda-> " << endl << endl;
				hmb->output_lambda();
				continue;
			}
			elif(want_to_do == "") {
				cout << "unrecognized" << endl << endl;
				--stop_time;
				continue;
			}
			else {
				cout << "unrecognized" << endl << endl;
				continue;
			}
		} while (stop_time);

		cout << endl << endl;
	}




};//end class Tree-----------------------------------------------------------------------end class Tree--------------------------------




//global???
//
Tree*hmb;//Ϊ��ռһ���ڴ棿
unsigned		Tree::Token_ptr = 0;
vector<string>	Tree::token;//Ҫ��ȫ������һ�£���Ȼ������֪��Ϊɶ??

vector<string> mydictionary::key_value= {												//��������
	"ZERO", "(\\f.(\\x.(x)))"	,
	"ONE", "(\\f.(\\x.(f(x))))"	,
	"TWO", "(\\f.(\\x.(f(f(x)))))"	,
	"THREE", "(\\f.(\\x.(f(f(f(x))))))"	,
	"FOUR", "(\\f.(\\x.(f(f(f(f(x)))))))"	,
	"FIVE", "(\\f.(\\x.(f(f(f(f(f(x))))))))"	,
	"SIX", "(\\f.(\\x.(f(f(f(f(f(f(x)))))))))"	,
	"SIXSEVEN","(67_NB)",
	"SEVEN", "(\\f.(\\x.(f(f(f(f(f(f(f(x))))))))))"	,
	"EIGHT", "(\\f.(\\x.(f(f(f(f(f(f(f(f(x)))))))))))"	,
	"NINE", "(\\f.(\\x.(f(f(f(f(f(f(f(f(f(x))))))))))))"	,
	"TEN", "(\\f.(\\x.(f(f(f(f(f(f(f(f(f(f(x)))))))))))))"	,
	"ELEVEN", "(\\f.(\\x.(f(f(f(f(f(f(f(f(f(f(f(x))))))))))))))"	,
	"TWELVE", "(\\f.(\\x.(f(f(f(f(f(f(f(f(f(f(f(f(x)))))))))))))))"	,
	"SUCC", "(\\n.(\\f.(\\x.(f((n(f))(x))))))"	,
	"PLUS", "(\\m.(\\n.((m SUCC)(n))))"	,
	"MULT", "(\\m.(\\n.(\\f.(m(n(f))))))"	,
	"POW", "(\\b.(\\e.(e(b))))"	,
	"PRED", "(\\n.(\\f.(\\x.(((n(\\g.(\\h.(h(g(f))))))(\\u.(x)))(\\v.(v))))))"	,
	"SUB", "(\\m.(\\n.((n PRED)(m))))"	,

	"TRUE", "(\\u.(\\v.(u)))"	,
	"FALSE", "(\\u.(\\v.(v)))"	,
	"AND", "(\\p.(\\q.((p(q))(p))))"	,
	"OR", "(\\p.(\\q.((p(p))(q))))"	,
	"NOT", "(\\p.(\\a.(\\b.((p(b))(a)))))"	,
	"IF", "(\\p.(\\a.(\\b.((p(a))(b)))))"	,
	"ISZERO", "(\\h.((h(\\t.FALSE))TRUE))"	,//?????????????????????

	"LEQ", "(\\m.(\\n.(ISZERO((SUB(m))(n)))))"	,
	"EQ", "(\\m.(\\n.((AND((LEQ(m))(n)))((LEQ(n))(m)))))"	,
	"LEQ", "(\\m.(\\n.(ISZERO((SUB(m))(n)))))"	,
	//(\\f.(\\n.(((IF(ISZERO(n)))ONE)((MULT(n))((f f)(PRED(n)))))))
	//(\\f.(\\n.(((ISZERO n)ONE)((MULT(n))((f f)(PRED n))))))
	"FACT1","(\\a.(\\b.((((b(\\t.(\\d.(\\e.e))))(\\i.(\\j.i)))(\\k.(\\l.(k l))))(\\p.(b(((a a)(\\r.(\\s.(((b(\\g.(\\w.(w(g r)))))(\\y.s))(\\z.z)))))p))))))",
	"FACT","(FACT1 FACT1)",
	"FACT1","(\\f.(\\n.(((ISZERO n)ONE)((MULT(n))((f f)(PRED n))))))",
	//(\\f.(\\n.(((IF(ISZERO(n)))ONE)((MULT(n))((f f)(PRED(n)))))))
//\f.\n.IF(ISZERO n) ONE(MULT n(f f(PRED n)))
//		(\f.(\n.((( IF(ISZERO (n))) ONE)((MULT (n))(f (f(PRED n))))   )))

	"FACT2","(\\f.(\\n.(((IF(ISZERO(n)))ONE)((MULT(n))(f(PRED(n)))))))",
	"YYY","(\\g. (  (\\x.( g(x x))) (\\x.(g(x x)))))",
	"FACTY","(YYY FACT2)",

	"MAX", "(\\x.(\\y.(((IF((LEQ(x))(y)))(y))(x))))",
	"MIN", "(\\x.(\\y.(((IF((LEQ(x))(y)))(x))(y))))",


	"CDR", "(\\p.(p FALSE))",
	"CAR", "(\\p.(p TRUE))",
	"CONS", "(\\x.(\\y.(\\f.((f(x))(y)))))",
	"NULL", "(\\p.(p(\\x.(\\y.FALSE))))",
	"NIL", "(\\x.TRUE)",
};
//<--------------------------------------------------------------------------------------------------main()-------------
int main() {//<---------------------------------------------------------------------------------------main()-----------------

	string mode="getline";
	string inner;

	while (true) {
		bool token_is_correct = true;

		cout << "Hello World!" << endl;
		getline(cin, inner);
		inner.erase(0, inner.find_first_not_of(" "));

		if (to_lower_string(inner) == "set") {
			string mode_history = mode;
			cout << "mode=";
			getline(cin, mode);
			mode = to_lower_string(mode);//
			if ((mode!=mode_history)&&(mode == "process" || mode == "final" || mode == "getline")) {
				cout <<endl<< "Success!" <<endl<< endl;
			}
			continue;
		}
		elif(to_lower_string(inner) == "func") {
			mydictionary* nb67 = new mydictionary();
			getline(cin, inner);
			if (to_lower_string(inner) == "define") {
				string s1, s2;
				cout << "Your function name is:";
				getline( cin,s1);
				cout << "Your function define is:";
				getline(cin, s2);
				mydictionary::function_define(s1, s2);
				cout<< "Success!" << endl << endl;
			}
			elif(to_lower_string(inner) == "check") {
				mydictionary::check();
			}
			elif(to_lower_string(inner) == "delete") {
				mydictionary::remove();
			}
			else {
				cout << "Unrecognized " << endl << endl;
			}
			continue;
		}
		elif(inner == "") {
			continue;
		}
		elif(to_lower_string(inner) =="quit"|| to_lower_string(inner) =="exit") {
			break;
		}
		elif(to_lower_string(inner) == "history"|| to_lower_string(inner) =="back") {
			inner = "history";
		}
		elif(to_lower_string(inner) == "help") {
			cout << help << endl<<endl<<endl;
			continue;
		}
		else {
			//pass
		}
		if (to_lower_string(inner) != "history") {
			token_is_correct= Tree::initial(inner); 
		}//���뱣����
		if (token_is_correct) {
			hmb = new Tree();
			Tree::work(hmb, mode);
		}
		else {
			cout << "wrong input" << endl << endl;
		}
	}
	//cout << "Tree" << endl;
	//hmb->print_Tree();
	//cout << "sentence" << endl;
	//Tree::output_sentence();
	//Tree::output_lambda_of_sentence();
	return 0;
}
//--------------------------------------------------------------------------------------------------end main();









//<--------------------------------------------------------------------�����Ķ���--------------------------------
Tree::Tree(Tree* father, bool init) {
	if (init) { Tree::Token_ptr = 0; }

	this->father = father;

	while (Token_ptr < token.size()) {
		if (token[Token_ptr] == left_parenthesis)//������
		{
			if (token[Token_ptr + 1] == lambda)			//  (lambda
			{
				if (father != 0) {
					if (father->left_attribute == "") {
						father->left_attribute = abstraction;
					}
					elif(father->right_attribute == "") {
						father->right_attribute = abstraction;
					}
				}

				attribute = abstraction;

				left_attribute = token[Token_ptr + 2];
				Token_ptr += 3;
				right_son = new Tree(this, false);


			}

			elif(token[Token_ptr + 1] == left_parenthesis)					//  ((
			{
				if (father != 0) {
					if (father->left_attribute == "") {
						father->left_attribute = application;
					}
					elif(father->right_attribute == "") {
						father->right_attribute = application;
					}
				}
				attribute = application;

				Token_ptr++;
				left_son = new Tree(this, false);
				/*...
				�ı���i
				��ʱtoken[i-1]һ���� ������
				token[i]һ���� ���� ���� ���� ֮һ,һ�·ֱ���֮
				...*/
				if (token[Token_ptr] == left_parenthesis) {
					right_son = new Tree(this, false);
				}
				elif(token[Token_ptr] == right_parenthesis) {
				}
				else {
					right_attribute = token[Token_ptr];
					Token_ptr += 1;
				}

			}

			else								// ��(�� �� �������� n f x y ֮�࣬��������  (f (x))
			{
				if (father != 0) {
					if (father->left_attribute == "") {
						father->left_attribute = application;
					}
					elif(father->right_attribute == "") {
						father->right_attribute = application;
					}
				}
				attribute = application;

				left_attribute = token[Token_ptr + 1];
				if (token[Token_ptr + 2] == right_parenthesis)			// ����,��Ϊ  (x)
				{
					right_attribute = isend;
					Token_ptr += 2;											//////why>?......dont return
				}
				else {
					Token_ptr += 2;
					right_son = new Tree(this, false);
				}

			}
		}

		elif(token[Token_ptr] == right_parenthesis)
		{
			Token_ptr++;
			return;
		}

		else
		{
			throw string(token[Token_ptr] + "  error");
		}

	}
}
Tree::~Tree() {
	Tree::Token_ptr = 0;
	if (left_son != 0) {
		left_son->~Tree();
	}
	if (right_son != 0) {
		right_son->~Tree();
	}
}


//
//static
void   Tree:: input_token(string s) {
	bool spilit = false;
	for (unsigned i = 0; i < s.length(); i++) {
		switch (s.at(i))
		{
		case('('):
			token.push_back(left_parenthesis);
			break;
		case(')'):
			token.push_back(right_parenthesis);
			break;
		case('\\'):
			token.push_back(lambda);
			break;
		case('.'):
			spilit = true;
			break;
		case(' '):
			spilit = true;
			break;
		case('\n'):
			break;
		default:
			if (token.back() == left_parenthesis || token.back() == right_parenthesis || token.back() == lambda || spilit) {
				token.push_back(s.substr(i, 1));
				spilit = false;
			}
			else {
				token.back() = token.back() + s.substr(i, 1);
			}
			break;
		}
	}
	return;
}
void   Tree:: add_parenthesis() {//������һ��()��token�������Ĳ���д��̫����
	vector<string>temp = token;
	token.clear();
	for (unsigned i = 0; i < temp.size();i++) {
		if (	((temp[i    ] != lambda) && (temp[i  ] != left_parenthesis) && (temp[i  ] != right_parenthesis))
			&&	((temp[i - 1] != lambda) && (temp[i-1] != left_parenthesis)    )) {
			token.push_back(left_parenthesis);
			token.push_back(temp[i]);
			token.push_back(right_parenthesis);
		}
		else {
			token.push_back(temp[i]);
		}
	}
}
bool   Tree:: check_token_right(string s) {

	if (s.at(0) != '(') { return false; }

	unsigned left_num = 1, right_num = 0;

	for (unsigned i = 1; i < s.size(); i++) {
		if (s.at(i) == '(') {
			left_num++;
		}
		if (s.at(i) == ')') {
			right_num++;
			if (s.at(i - 1) == '(') {
				return false;
			}
		}

	}
	return left_num == right_num;

}
void   Tree:: calculate() {//�������ŵĸ���
	int num = 0;
	for (unsigned i = 0; i < token.size(); i++) {
		if (token[i] == right_parenthesis && token[i - 2] != left_parenthesis) {
			num++;
		}
	}
	cout << "number=" << num << endl << endl;
}
//
//
//���ݵ�ǰ�������� token ת�ɴ�����Ӧ����ȫ��ʽ
void   Tree::to_token(bool should_clear) {//��ʼ�� Ĭ��should��clear Ϊtrue����վɵ�
	if (should_clear) { token.clear(); }

	if (attribute == application)
	{
		token.push_back(left_parenthesis);

		if (left_attribute == abstraction || left_attribute == application) {
			left_son->to_token(false);
		}
		else {
			token.push_back(left_attribute);
		}

		if (right_attribute == abstraction || right_attribute == application) {
			right_son->to_token(false);
		}
		else {						//isend
			//pass
		}
	}

	elif(attribute == abstraction) {
		token.push_back(left_parenthesis);
		token.push_back(lambda);
		token.push_back(left_attribute);
		right_son->to_token(false);
	}

	token.push_back(right_parenthesis);//return ǰ��� ������
}
//
//
//
//
//
void Tree::output_token() {

	for (string i : token) 
	{
		cout << i << endl;
	}

	cout << endl << endl;
}
void Tree::output_lambda() {
		string out = "";
		bool has_dot = false;
		bool has_space = false;

		for (unsigned i = 0; i < token.size();i++) {

			if (token[i]  == left_parenthesis) {
				if (token[i + 2] != right_parenthesis) {//�������
					out = out + "(";
					has_space = false;
				}
				else {//��������ֻ��һ���������������ÿ�����΢��һ��
					if (has_space) { out = out + " ";}
					//û�� else
					out = out + token[i+1];
					has_space = false;
					i+=2;//��Ծһ��
				}
			}
			elif(token[i] == right_parenthesis) {
				out = out + ")";
				has_space = false;
			}
			elif(token[i] == lambda) {
				out = out + "\\";
				has_dot = true;
				has_space = false;
			}
			else {

				if (has_dot) {
					out = out + token[i] + ".";
					has_dot = false;
				}
				elif(has_space) {
					//out = out + " " + i;
					out = out + token[i];
					has_space = false;
				}
				else {
					out = out + token[i];
					has_space = true;
				}
			}
		}
		cout << out << endl;
	}
void Tree::a_change_token() {//����֧��������ʽ,������token,����������

		vector<string>first_searched_symbollist;
		vector<string>more_than_once_symbollist;
		unsigned alphabet_ptr = 0;
		string symbol_old, symbol_new;

		for (unsigned i = 0; i < token.size(); i++) {
			if (token[i] == lambda) {
				if (!is_in(token[i + 1], first_searched_symbollist)) {
					first_searched_symbollist.push_back(token[i + 1]);
				}
				else {
					if (!is_in(token[i + 1], more_than_once_symbollist)) {
						more_than_once_symbollist.push_back(token[i + 1]);
					}
				}
			}
		}

		for (unsigned i = 0; i < token.size(); i++) {
			if ((token[i] == lambda) && is_in(token[i + 1], more_than_once_symbollist)) {//should replace

				while (is_in(alphabet[alphabet_ptr], first_searched_symbollist)) {//find new symbol
					alphabet_ptr++;
					if (alphabet_ptr == alphabet.size() - 1) {
						cout << "woc��������ô���" << endl;
						alphabet_ptr = 0;
					}
				}
				symbol_old = token[i + 1];
				symbol_new = alphabet[alphabet_ptr];
				token[i + 1] = symbol_new;
				first_searched_symbollist.push_back(symbol_new);
				more_than_once_symbollist.push_back(symbol_new);

				int j = i + 1;
				int num = 1;
				while (num > 0) {			//replace
					if (token[j] == left_parenthesis) { num++; }
					elif(token[j] == right_parenthesis) { num--; }
					elif(token[j] == symbol_old) { token[j] = symbol_new; }
					j++;
				}
			}
		}

		//for (string i : symbollist) { cout << i << " "; }
		//cout << endl;
	}
//a��Լ ������bug,���������϶�����ɻ��ң�Ҳ����û��bug,����Ч�ʵ������
//
//
void Tree::print_Tree() {
	cout << this->attribute << endl;
	cout << left_attribute << endl;
	cout << right_attribute << endl;
	cout << endl;
	if (left_son != 0) {
		left_son->print_Tree();
	}
	if (right_son != 0) {
		right_son->print_Tree();
	}
}










//B��Լ��֮ǰ�Ĵ���
vector<string>  Tree::temp_string_list;
vector<string>	Tree::searched_symbol_list;//����B��Լ֮ǰ�ĳ�ͻ����
vector<string>  Tree::conflict_symbol_list;//����B��Լ֮ǰ�ĳ�ͻ����


bool Tree:: find_conflict_before_B(bool init) {//= true
	
	if (init) {//Ĭ��Ϊtrue
		temp_string_list.clear();
	}

	bool have_found_conflict = false;		//	�൱��init


	if ((this->attribute == abstraction) && (is_in(left_attribute, conflict_symbol_list))) {
		temp_string_list.push_back(left_attribute);
		have_found_conflict = true;
	}

	//
	if (left_son == NULL) {
		if (!is_in(left_attribute, searched_symbol_list)) {
			searched_symbol_list.push_back(left_attribute);
		}
	}
	else {
		if (left_son->find_conflict_before_B(false) == true) {
			have_found_conflict = true;
		}
	}
	//
	if ((right_son == NULL) && (right_attribute != isend)) {
		if (!is_in(right_attribute, searched_symbol_list)) {
			searched_symbol_list.push_back(right_attribute);
		}
	}
	elif(right_son != NULL) {
		if (right_son->find_conflict_before_B(false) == true) {
			have_found_conflict = true;
		}
	}

	conflict_symbol_list = temp_string_list;//��ʱ�������������ĳ�ͻ����

	return have_found_conflict;
}
void Tree:: a_solve_conflict_before_B(string symbol_old, string symbol_new_new, bool shoule_solve_conflict) {// = false

	if (!shoule_solve_conflict) {//Ĭ�� = false
		if (this->attribute == abstraction) {
			shoule_solve_conflict = true;
		}
	}

	if (shoule_solve_conflict) {//

		if (this->left_attribute == symbol_old) {
			left_attribute = symbol_new_new;
		}
		elif(left_son != NULL) {
			left_son->a_solve_conflict_before_B(symbol_old, symbol_new_new, shoule_solve_conflict);
		}

		if (this->right_attribute == symbol_old) {
			right_attribute = symbol_new_new;
		}
		elif(right_son != NULL) {
			right_son->a_solve_conflict_before_B(symbol_old, symbol_new_new, shoule_solve_conflict);
		}

		//
	}

	return;
}
//<----------------------------------------------------------------------------------------------
void Tree:: B_replace_to_subtree(string symbol_old, bool init) {//= true

	if (init) {												//��ʼ�� Ӧ�ý����ͻ,�Ҿ������֮ǰ���ұ���abs�����г�ͻ��������
		conflict_symbol_list.clear();
		searched_symbol_list.clear();
		for (string i : token) {									//����token���е�ֵ�������Ż�����Ϊ�еĲ�������Ԫ
			if ((i != left_parenthesis) && (i != right_parenthesis) && (i != isend) && (i != lambda)) {
				conflict_symbol_list.push_back(i);
				searched_symbol_list.push_back(i);
			}
		}
		//////conflict_symbol_list.push_back(symbol_new);�� token ��ͷ�Ұɣ���Ϊ���������ˣ�token�������������Ϣ  (�������for
		//////searched_symbol_list.push_back(symbol_new);
		bool have_found_conflict = this->find_conflict_before_B();//ִ�����conflict_symbol_list �����ֵ�ظ��ĵ㣨����������Ķ���һ��symbol_old �� ��searched_symbol_list��ø��ḻ

		//<----------------------------------------------------------------------�����Ż�����û������ȫ��gg
		{//<----------------------------------------------------------------------Ȼ����conflict_symbol_listȥ���Ǹ�symbol_old,�����������Ż�
			sort(conflict_symbol_list.begin(), conflict_symbol_list.end());
			conflict_symbol_list.erase(unique(conflict_symbol_list.begin(), conflict_symbol_list.end()), conflict_symbol_list.end());
			vector<string>::iterator result = find(conflict_symbol_list.begin(), conflict_symbol_list.end(), symbol_old);
			if (result != conflict_symbol_list.end()) {
				conflict_symbol_list.erase(result);
			}


			sort(searched_symbol_list.begin(), searched_symbol_list.end());
			searched_symbol_list.erase(unique(searched_symbol_list.begin(), searched_symbol_list.end()), searched_symbol_list.end());
		}


		if (have_found_conflict) {
			for (string symbol_new : conflict_symbol_list) {
				string symbol_new_new;

				for (string i : alphabet) {
					if (!is_in(i, searched_symbol_list)) {
						symbol_new_new = i;
						break;
					}
				}

				searched_symbol_list.push_back(symbol_new_new);//<-------------------------------------------�ǵ�push��ȥ
				this->a_solve_conflict_before_B(symbol_new, symbol_new_new);
			}
		}
	}//end init

	if (this->left_attribute == symbol_old) {//1.��//<----------------------------------------------------������ȫ����new�İ�

		if (attribute == abstraction) {//<------------------------------------------------------------------����ܹؼ�
			return;
		}

		if ((right_attribute == isend) && (this->father != NULL)) {		//���У�Ϊ�˰ѵ�����һ�£��������Ź���
			if (this == father->left_son) {
				father->left_son = new Tree(father);/////////////////////////////////////////////
				father->left_attribute = father->left_son->attribute;
			}
			elif(this == father->right_son) {
				father->right_son = new Tree(father);
				father->right_attribute = father->right_son->attribute;
			}
			return;
		}//end if
		elif((right_attribute == isend) && (this->father == NULL)) {		//���У�ͬ��,��Ҫɾ���������Ǹ�����
			//this = this->left_son();//<++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++=���ܻ�ռ�ݹ����ڴ�
			left_son = new Tree(this);
			left_attribute = left_son->attribute;////��֪����ôд��
			//new Tree();

			return;
		}
		else {									//���������
			left_son = new Tree(this);
			left_attribute = left_son->attribute;
		}

	}
	elif(left_attribute == application || left_attribute == abstraction) {//1.��
		left_son->B_replace_to_subtree(symbol_old, false);
	}

	if (this->right_attribute == symbol_old) {//2.��
		right_son = new Tree(this);
		right_attribute = right_son->attribute;
	}
	elif(right_attribute == application || right_attribute == abstraction) {//2.��
		right_son->B_replace_to_subtree(symbol_old, false);
	}
	//else
	return;
}

void Tree:: B_replace_to_string(string symbol_old, string symbol_new, bool init) {// = true

	if (init &&  symbol_old != symbol_new) {												//��ʼ�� Ӧ�ý����ͻ
		conflict_symbol_list.clear();
		searched_symbol_list.clear();
		conflict_symbol_list.push_back(symbol_new);
		searched_symbol_list.push_back(symbol_new);
		bool have_found_conflict = this->find_conflict_before_B();//���symbol_new ֱ�Ӿ��ǳ�ͻ��

		string symbol_new_new;
		if (have_found_conflict) {
			for (string i : alphabet) {
				if (!is_in(i, searched_symbol_list)) {
					symbol_new_new = i;
					//cout << "new new:  "<<i << endl << endl;//------------------------------------------
					break;
				}
			}
			this->a_solve_conflict_before_B(symbol_new, symbol_new_new);
		}
	}//end init

	if (this->left_attribute == symbol_old) {//<----------------------------------------------------������ȫ�������İ�

		if (attribute == abstraction) {//<---------------------------------------------------------����ܹؼ���������֮ǰ�����ͻ�ķ���֮��
			return;
		}

		left_attribute = symbol_new;
	}
	elif(left_son != NULL) {
		left_son->B_replace_to_string(symbol_old, symbol_new, false);
	}



	if (this->right_attribute == symbol_old) {
		right_attribute = symbol_new;
	}
	elif(right_son != NULL) {
		right_son->B_replace_to_string(symbol_old, symbol_new, false);
	}
	return;
}

void Tree:: point_to_left_and_right_before_B() {

	Tree*temp1 = this->left_son;
	Tree*temp3 = this->right_son;

	this->left_son = this->left_son->right_son;
	this->left_attribute = left_son->attribute;
	this->left_son->father = this;

	this->right_son = this->right_son->right_son;
	this->right_attribute = right_son->attribute;
	this->right_son->father = this;


	temp1->right_son = NULL;
	temp1->~Tree();
	temp3->left_son = 0;///////////
	temp3->right_son = 0;
	temp3->~Tree();
}
void Tree:: goto_left_and_delete_right_before_B() {

	this->right_son->~Tree();
	Tree*temp1 = this->left_son;
	Tree*temp2 = this->left_son->right_son;

	this->attribute = temp2->attribute;
	this->left_attribute = temp2->left_attribute;
	this->right_attribute = temp2->right_attribute;
	this->left_son = temp2->left_son;
	this->right_son = temp2->right_son;

	if (this->left_son != NULL) {		//�������Ҫ�����������������ϵ��Լ����޷�ָ������
		left_son->father = this;
	}
	if (this->right_son != NULL) {
		right_son->father = this;
	}

	if (this->father != NULL) {			//�������Ҫ���������ĸ��ڵ㲻֪���Լ�������
		if (father->left_son == this) {
			father->left_attribute = this->attribute;
		}
		elif(father->right_son == this) {
			father->right_attribute = this->attribute;
		}
	}

	temp1->right_son = NULL;
	temp1->~Tree();
	temp2->left_son = 0;
	temp2->right_son = 0;
	temp2->~Tree();
}

//B��Լ
bool Tree:: B_change(bool has_changed) {//-------------------------------------------------------B ��Լ ������ʲô˳�򣿣���
	//�Ѿ�Ĭ��has changed false



	   	  


	if (this->attribute == application && (!has_changed)) {



		if (left_attribute == abstraction ) {/////////////////////////////
			string symbol_old = left_son->left_attribute;//��¼�ɵ�symbol,����B��Լ,��2�����


			if (right_attribute == abstraction ) {						//1.�ұ�Ϊ���������滻

				right_son->to_token();//�޸���token,С��
				this->goto_left_and_delete_right_before_B();
				this->B_replace_to_subtree(symbol_old);//�Ҿ��ò���ҪԼ����Ϊû������Ԫ������������������������������������������
				has_changed = true;									//��ʾ�Ѿ�Լ����
			}




			elif(right_attribute == application) {		//2. �ұ�ΪӦ�ã���2�����

				if (right_son->right_attribute == isend) {//2.1 �ұߵ��ұ���end�������ұߵ��������ĸ��������ǡ���

					string symbol_new = right_son->left_attribute;
					this->goto_left_and_delete_right_before_B();
					this->B_replace_to_string(symbol_old, symbol_new);
					has_changed = true;
				}
				//


				//
				else {									//2.2 �ұߵ��ұ���һ��
					
					//if (!has_changed && (left_son != 0)) { has_changed = left_son->B_change(has_changed); }//???????/----------
					//if (!has_changed) { has_changed = right_son->B_change(has_changed); }//��˵���û�ã�����(---------------


					//&&right_son->have_a_app()==false//????????????????????
					if (!has_changed) {		//2.2 �е��ѣ�ʵ���ϵݹ��ж��Ƿ��Լ��[δ�ı�]��˼�� �Ӳ�û�ҵ���Լ�ĵط�����������Ϊ��������---//
						right_son->to_token();//�޸���token,С��
						this->goto_left_and_delete_right_before_B();//��û��
						this->B_replace_to_subtree(symbol_old);
						has_changed = true;
					}
				}

			}
		}
	}




	if (left_son != NULL) {//����----------------------------------------------------1111
		if (has_changed) {//�Ѿ�Լ����
			return true;//˵���˴��Ѿ�Լ��������дhas changed=true
		}
		else {
			has_changed = left_son->B_change(has_changed);
		}
	}//END LEFT




	
	if (right_son != NULL) {//�Һ�---------------------------------------------------------------------222
		if (has_changed) {
			return true;
		}
		else {
			has_changed = right_son->B_change(has_changed);
		}
	}//END RIGHT


	// (   (  (\\x.(\\y.(x))) (a)  ) (((\#.((# #)$))(\#.((# #)$)))$)       )

	
	return has_changed;
}