import sys

def solve():
    input = sys.stdin.readline
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        a = list(map(int, input().split()))
        print("YES" if k in a else "NO")

if __name__ == "__main__":
    solve()