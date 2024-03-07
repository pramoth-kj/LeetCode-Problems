
int size(struct ListNode *head){
  int cnt = 0;
  while(head != NULL){
    cnt++;
    head = head->next;
  }
  return cnt;
}
struct ListNode* middleNode(struct ListNode* head){
  int middle = size(head)/2 + 1;
  int cnt = 1;
  while (cnt < middle) {
      cnt++;
      struct ListNode *tmp = head;
      head = head->next;
      free(tmp);
  }
    return head;
}