#include <cstring>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_NAME_LEN 35
#define MAX_ROUTE_NUM 5005
#define MIN_VELOCITY 0

struct Path
{
  int tail, vel, prefixPath;
  Path(int _tail, int _vel, int _prefix)
  {
    tail = _tail;
    vel = _vel;
    prefixPath = _prefix;
  }
};
vector<struct Path> paths;

bool getIsVisited(int pathIdx, int city)
{
  for (int idx = pathIdx; ~idx; idx = paths[idx].prefixPath)
  {
    if (paths[idx].tail == city)
    {
      return true;
    }
  }
  return false;
}

struct Edge
{
  int dst, vel, nxt;
} edges[MAX_ROUTE_NUM * 2];
int graph[MAX_ROUTE_NUM * 2];
int edgeCnt;

void pushEdge(int a, int b, int vel)
{
  edges[edgeCnt].dst = b;
  edges[edgeCnt].vel = vel;
  edges[edgeCnt].nxt = graph[a];
  graph[a] = edgeCnt++;
}

void initGraph()
{
  memset(graph, -1, MAX_ROUTE_NUM * 2 * sizeof(int));
  edgeCnt = 0;
}

int cityNum;
map<string, int> dic;
map<int, string> invDic;

int pushCity(char *cityName)
{
  map<string, int>::iterator it = dic.find(cityName);
  if (it == dic.end())
  {
    dic[cityName] = cityNum;
    invDic[cityNum] = cityName;
    cityNum++;
    return cityNum - 1;
  }
  else
  {
    return it->second;
  }
}

void init()
{
  initGraph();
  cityNum = 0;
  dic.clear();
  invDic.clear();
}

int main()
{
  int routeNum, cityNum, startCity, endCity, vel, solved;
  char startCityName[MAX_NAME_LEN], endCityName[MAX_NAME_LEN];
  bool firstCase = true;
  queue<int> q;

  while (~scanf("%d", &routeNum))
  {
    init();
    solved = -1;
    paths.clear();
    while (!q.empty())
    {
      q.pop();
    }

    while (routeNum--)
    {
      scanf("%s %s %d", startCityName, endCityName, &vel);

      startCity = pushCity(startCityName);
      endCity = pushCity(endCityName);

      pushEdge(startCity, endCity, vel);
      pushEdge(endCity, startCity, vel);
    }
    scanf("%s %s", startCityName, endCityName);
    startCity = pushCity(startCityName);
    endCity = pushCity(endCityName);

    paths.push_back(Path(startCity, MIN_VELOCITY, -1));
    q.push(0);
    while (!q.empty() && solved < 0)
    {
      int pathIdx = q.front();
      struct Path &path = paths[pathIdx];
      map<int, int> opt; // dst => vel
      map<int, int>::iterator it;
      int parent = path.tail;
      int limit = path.vel;
      q.pop();
      for (int e = graph[parent]; ~e; e = edges[e].nxt)
      {
        int child = edges[e].dst;
        int vel = edges[e].vel;
        if (vel >= limit && !getIsVisited(pathIdx, child))
        {
          it = opt.find(child);
          if (it == opt.end())
          {
            opt[child] = vel;
          }
          else
          {
            it->second = min(it->second, vel);
          }
        }
      }
      for (it = opt.begin(); it != opt.end(); ++it)
      {
        int pathLastIdx;
        paths.push_back(Path(it->first, it->second, pathIdx));
        pathLastIdx = paths.size() - 1;
        q.push(pathLastIdx);
        if (it->first == endCity && solved < 0)
        {
          solved = pathLastIdx;
        }
      }
    }

    if (!firstCase)
    {
      puts("");
    }
    firstCase = false;

    if (solved < 0)
    {
      puts("No valid route.");
    }
    else
    {
      vector<string> ans;
      vector<string>::reverse_iterator rit;
      for (int idx = solved; ~idx; idx = paths[idx].prefixPath)
      {
        int city = paths[idx].tail;
        ans.push_back(invDic[city]);
      }
      for (rit = ans.rbegin(); rit != ans.rend(); ++rit)
      {
        printf("%s", rit->c_str());
        if (rit + 1 == ans.rend())
        {
          putchar('\n');
        }
        else
        {
          putchar(' ');
        }
      }
    }
  }
}
