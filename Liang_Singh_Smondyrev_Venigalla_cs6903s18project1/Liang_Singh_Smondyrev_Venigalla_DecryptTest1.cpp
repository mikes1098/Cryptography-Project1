//
//  proj01 - test 1
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int
match_pattern (vector < int >&cipher_text)
{
  // analysis ciphertext based on location and occurance
  int a, b, c, d, f;
  int count_a = 0, count_b = 0, count_c = 0, count_d = 0, count_f = 0;
  a = cipher_text[240];		// b-positon at palintext 1
  b = cipher_text[148];		// b-positon at plaintext 2
  c = cipher_text[34];
  d = cipher_text[18];
  f = cipher_text[50];

  for (int i = 0; i < cipher_text.size (); i++)
    {
      if (cipher_text[i] == a)
	{
	  count_a++;
	}
      if (cipher_text[i] == b)
	{
	  count_b++;
	}
      if (cipher_text[i] == c)
	{
	  count_c++;
	}
      if (cipher_text[i] == d)
	{
	  count_d++;
	}
      if (cipher_text[i] == f)
	{
	  count_f++;
	}
    }

  //hard code position based on plaintext analysis
  if (count_a == 9 && cipher_text[240] == a && cipher_text[267] == a
      && cipher_text[282] == a && cipher_text[354] == a
      && cipher_text[389] == a && cipher_text[390] == a
      && cipher_text[414] == a && cipher_text[468] == a
      && cipher_text[477] == a)
    {
      return 1;
    }
  else if (count_b == 11 && cipher_text[148] == b && cipher_text[174] == b
	   && cipher_text[189] == b && cipher_text[204] == b
	   && cipher_text[239] == b && cipher_text[253] == b
	   && cipher_text[366] == b && cipher_text[367] == b
	   && cipher_text[378] == b && cipher_text[421] == b
	   && cipher_text[482] == b)
    {
      return 2;
    }
  else if (count_c == 10 && cipher_text[34] == c && cipher_text[56] == c
	   && cipher_text[110] == c && cipher_text[125] == c
	   && cipher_text[141] == c && cipher_text[227] == c
	   && cipher_text[248] == c && cipher_text[314] == c
	   && cipher_text[317] == c && cipher_text[320] == c)
    {
      return 3;
    }
  else if (count_d == 8 && cipher_text[18] == d && cipher_text[61] == d
	   && cipher_text[118] == d && cipher_text[148] == d
	   && cipher_text[300] == d && cipher_text[360] == d
	   && cipher_text[384] == d && cipher_text[447] == d)
    {
      return 4;
    }
  else if (count_f == 7 && cipher_text[50] == f && cipher_text[84] == f
	   && cipher_text[105] == f && cipher_text[254] == f
	   && cipher_text[259] == f && cipher_text[391] == f
	   && cipher_text[466] == f)
    {
      return 5;
    }
  else
    {
      return 0;
    }
}

void
delete_comma (vector < int >&cipher, string & input)
{
  int tempNum = 0;
  for (int i = 0; i < input.length (); i++)
    {
      if (input[i] != ',')
	{
	  tempNum = (tempNum * 10) + (int) (input[i] - '0');
	}
      else
	{
	  cipher.push_back (tempNum);
	  tempNum = 0;
	}
    }
}

int
main (int argc, const char *argv[])
{
  string p1 =
    "masterwork swept squanders grounders idolatries swapper pave croupier dramatists magnified hypnoses delivery tassels marquise entailments circuits crampon nationalism nictitation anticapitalists dancingly soothly patriarchs goodie whickers baggy omnipotent sadist ameba processions beggary rename nonassertively macerators lectureship shipwrights sadden backups rhymer offstage schistose ebbs restorer graecizes subjoining leathering smocks leukocyte waled temperer embroglios bolivar repines teletyp ";
  string p2 =
    "wharves locoisms tearjerkers remiss chops duties prolonged inequities minnows itemized thematically scorecard deliverers jokingly semiosis claspers brazenness grateful collarbones stamping bittersweets habilitation endorsers decrepitly tambourine shadowboxes adopting ingenuous disquisitions quietist innovates mingles nationals disparaging exults realtor cockade rubberizing tubercled unremitting sloppiest algin knuckleball disengage domes doltishly encyclics spectroscopically debauched circumsola ";
  string p3 =
    "ozonise creosotes disruption neighborly lunier shagging balancing adriatic dick guesstimate storminess jest soberer spun toolbox crochet firebreak parliamentary undismayed lintiest homoeroticism silverfishes cornstalk digest subtler ruck cairns wombat working synapsed diamonding association opalescence crenation bumblebees undetected sandwiching unpeoples polishes schoolwork familarity flaying slued soothers splenification dare hydrology gourami alligators varsity statuettes gainly feeding filme ";
  string p4 =
    "autarky sartor terbium synapse herr eugenicists isthmian reembarks spinet dictaphone ecology carinae coeducational carburizing undulated twopenny subscriptions wrigglier scaliness enthrallingly carvers russified rejoice anaconda switzerland sallows devotedly pledgees incongruous miriest nonextraditable extrospection clipping souffle mimicry interrupts reputably reteaches quicksets bankroll hallucinated unzealous invocation winless yacking shinbone tonal vasoconstrictive manioc gourami purling ey ";
  string p5 =
    "championships iatrogenic maniacally antonym schoolboy shyly leafhoppers inturned sunbathing overrefined obliterations discus maintain cranked uniters twangled impairer wreakers forewings silesia occupance headroom foresting ornithologists shims lackaday benumbedness gloomy sententious fussing flagrant consonance profligately scutcheons honda swooned headworks zeins intermezzo adaptions elbow ocotillos denim japers thalamic corinthians restraightening kowtowed embarrasses latissimi impoverished s ";

  string input_string;
  vector < int >cipher_text;
  int result;

  cout << "Enter the ciphertext: " << endl;
  getline (cin, input_string);

  input_string += ",";

  delete_comma (cipher_text, input_string);
  
  cout << "My plaintext guess is: " << endl;
  result = match_pattern (cipher_text);
  if (result == 1)
    {
      cout << p1 << endl;
    }
  else if (result == 2)
    {
      cout << p2 << endl;
    }
  else if (result == 3)
    {
      cout << p3 << endl;
    }
  else if (result == 4)
    {
      cout << p4 << endl;
    }
  else if (result == 5)
    {
      cout << p5 << endl;
    }
  else
    {
      cout << "Please use decrypt-test2 for test 2." << endl;
    }

  return 0;
}

//https://www.onlinegdb.com/online_c_compiler
