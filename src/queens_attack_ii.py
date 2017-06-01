#!/bin/python3

import sys


def count_in_direction(n, rSqr1, cSqr1, delta, obstacles):
    """
    n: int -> c,r of board
    rSqr1, cSqr1: int -> queen's sqr
    delta: tuple(int,int) -> change to r and c to gontinue path
    obstacles: list of obstacles
    """
    this_sqr = [rSqr1,cSqr1]
    attackable_ctr = 0
    while True:
        this_sqr[0]+=delta[0]
        this_sqr[1]+=delta[1]
        off_sides = (this_sqr[0] < 1 or this_sqr[0] > n)
        off_top_bottom = (this_sqr[1] < 1 or this_sqr[1] > n)
        
        if off_sides or off_top_bottom:
            return attackable_ctr
        if this_sqr in obstacles:
            return attackable_ctr
        
        attackable_ctr+=1


n,k = input().strip().split(' ')
n,k = [int(n),int(k)]
rQueen,cQueen = input().strip().split(' ')
rQueen,cQueen = [int(rQueen),int(cQueen)]
obstacles =[]
for a0 in range(k):
    rObstacle,cObstacle = input().strip().split(' ')
    obstacle = [int(rObstacle),int(cObstacle)]
    obstacles.append(obstacle)
    
deltas = [(-1,0),(-1,1),(0,1),(1,1),(1,-1),(0,-1),(-1,-1),(1,0)]
attackable_sqrs = 0

for delta in deltas:
    attackable_sqrs += count_in_direction(n,rQueen,cQueen,delta,obstacles)
print(attackable_sqrs)

