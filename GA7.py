TASK = 1  # 2 для задачи с коробками

if TASK == 1:
    print('кол-во лекций')
    n = int(input())
    lectures = []
    print('время начала и время конца')
    for _ in range(n):
        s, f = map(int, input().split())
        lectures.append((f, s))
    lectures.sort()
    count = 0
    last_end = -1
    for end, start in lectures:
        if start >= last_end:
            count += 1
            last_end = end
    
    print(count, "лекций поместилось")

elif TASK == 2:
    def get_sum(box):
        return box[0] + box[1]
    print('кол-во коробок')
    n = int(input())
    boxes = []
    print('вес и грузоподъемность')
    for _ in range(n):
        w, m = map(int, input().split())
        boxes.append((w, m))
    boxes.sort(key=get_sum)
    total_w = 0
    count = 0
    for weight, _max in boxes:
        if total_w <= _max:
            count += 1
            total_w += weight
    
    print(count, "коробок поместилось")