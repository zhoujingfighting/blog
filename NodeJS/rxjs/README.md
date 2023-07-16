## Learning rxjs

rxjs : Reactive extension for javaScript


## 知识点结合

### Observable

- It is a data stream 
    - In a ecommerce shopping cart application
        - orderStatus value -NULL
        - User comes and places an order
            - order status will change over time // continiusly changing
            - orderStatus = order placed
            - orderStatus = order received
            - orderStatus = order processing
            - orderStatus = order submitted
            - orderStatus = order completed

* Observables emit data over a period of time
* Observables needs to be subscribed else it won't do anything on its own
* An Observable has 3 methods namely -> next,complete and error

### Subscriber

- It will listen to the Observable for data changes/updates
- My app is dashboard
    - orderStatus - latest values always - since we have subscribed to it