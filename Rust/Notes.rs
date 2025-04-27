    /* Trait like params and return value */

{
    trait ITest {}
    struct MyStruct {}
    impl ITest for MyStruct {}

    fn getFoo(field: &impl ITest) {}
    fn retFoo() -> impl Itest {}
}

/*----------------------------------*/

    /* trait bound */

{
    trait ITest {}
    trait OneMoreTrait {}

    // insted this
    fn display(field: &impl ITest) {}
    // this
    fn display<T: ITest>(field: &T) {}
    //also posible do this
    fn display<T>(field: &T) where T: ITest {}
    // and one more case
    fn display(field: &(impl ITest + OneMoreTrait)) {}
}

/*----------------------------------*/

    /* Gobal impl trait */

{
    struct MyStruct {}

    trait ITest {}

    impl<T> ITest for T {
        fn traitFoo(&self) {}
    }

    fn foo() {
        let obj = MyStruct{};
        obj.traitFoo();
    }
}

/*----------------------------------*/

    /* Operators overloads*/

    /*
        full list of operators:
        https://doc.rust-lang.org/std/ops/index.html.
    */

{
    use std::ops::Add;

    struct MyStruct {
        value: u32
    }

    impl Add for Counter {
        type Output = Counter;
        fn add(self, other: Counter) -> Counter {
            Output {
                value: self.value + other.value
            }
        }
    }

    fn test() {
        let counter1 = Counter{value: 1.to_owned()};
        let counter2 = Counter{value: 1.to_owned()};

        let res: Coutner = counter1 + counter2;
    }
}

/*----------------------------------*/

    /* type */

{
    trait ITest {
        type Unit;
        fn foo() -> Self::Unit;
    }

    struct MyStruct {}

    impl Itest for MyStruct {
        type Unit = i32;
        fn foo() -> Self::Unit {
            /* ... */
        }
    }
}

/*----------------------------------*/

    /* Polimorphism */

{
    trait ITest {
        fn foo(&self);
    }

    struct MyStruct {}
    struct OneMoreStruct {}

    impl ITest for MyStruct {
        fn foo(&self) {
            /* ... */
        }
    }
    impl ITest for OneMoreStruct {
        fn foo(&self) {
            /* ... */
        }
    }

    fn test() {
        let my = MyStruct {};
        let one = OneMoreStruct {};

        let vec: Vec<&dyn ITest> = vec![&my, &one];
        
        for elem in vec {
            elem.foo();
        }
    }
}

/*----------------------------------*/

    /* Ref lifetime */

{
    fn foo() -> &'a str {
        /* ... */
    }

    fn foo<'a>(first: &'a str, second: &'a str) -> &'a str {
        /* ... */
    }

    struct MyStruct<'a> {
        field: &'a str,
    }

    fn test() {
        let somStr = "some".to_owned();
        let temp = MyStruct{ field: &domeStr };
    }

    impl<'a> MyStruct<'a> {
        fn memberFoo(&self) {
            println!(self.field);
        }

        fn oneMore<'b>(&self, other: 'b str) -> &'b str {
            other
        }
    }
}

/*----------------------------------*/

    /* Iterators */

{
    trait Iterator {
        type Item;
        fn next(&mut self) -> Option<Self::Item>;
    }

    struct Counter {
        count: u32,
    }

    impl Iterator for Counter {
        type Item = u32;
        
        fn next(&mut self) -> Option<Self::Item> {
            if self.coutn < 10 {
                self.count += 1;
                Some(self.count)
            } else {
                None
            }
        }
    }

    fn test() {
        let mut counter = Counter { count: 0 };
        for num in &mut counter {
            println!("Num: {}", num);
        }
    }

    trait IntoIterator {
        type Item;
        type IntoIter = std::vec::IntoIter<Self::Item>;
        fn into_iter(self) -> Self::IntoIter;
    }

    /* Return Iterator for specific type */
    impl IntoIterator for Counter {
        type Item = u32;
        type IntoIter = std::vec::IntoIter<Self::Itme>;
        fn into_iter(self) -> Self::IntoIter {
            self.count.into_iter()
        }
    }

    fn useCollectAndFilter() {
        let vec = vec![1, 2, 3, 4, 5];
        // Just make a new collection from iterator
        let other = vec.into_iter().filter(|num| num >= 3).collect();
    }

    trait IterMethods {
        fn collect();
        fn filter(/* closing */);
        fn map(/* closing */);
        fn skip(/* count to skip first elems */);
        fn take(/* count to take */);
        fn for_each(/* closing */);
        fn chain(/* iter to collection for union */);
        fn sort_by(/* closing */);
    }
}

/*----------------------------------*/

    /* Crate, lib, mod */

    /*
        - backend
          - Cargo.toml // Crate
          - src
            - lib.rs
            - someFile.rs
            - submodule
              - mod.rs
              - oneMore.rs
    */

/*----------------------------------*/

    /* Input/Output*/

{
    fn test() {
        let mut input = String::new();
        let test = std::io::stdin();
        test.read_line(input);
    }
}

/*----------------------------------*/

    /* Unsafe context */

{
    unsafe fn danger() { /* ... */}

    static mut COUNTER: i32 = 0;

    extern "C" {
        fn printf(format: *const u8, ...) -> i32;
    }

    fn test() {
        let x = 42;
        let ptr: *const i32 = &x;

        unsafe {
            *ptr;
            danger();
            COUNTER += 1;
            printf("Hello");
        }
    }
}

/*----------------------------------*/

    /* Threads */

{
    use std::thread;
    use std::sync::{Mutex, Arc, mpsc};

    fn test() {
        {
            let text = String::from("World");
            let th = thread::spawn(move || {
                println!("Hello");
                println!(text);
            });
            th.join();
        }
        
        {
            let data = Arc::new(vec![1, 2, 3, 4, 5]);
            let clone1 = Arc::clone(&data);
            let clone2 = Arc::clone(&data);
    
            let th1 = thread::spawn(move || {
                println!(clone1.len());
            });
    
            let th2 = thread::spawn(move || {
                println!(clone2.len());
            });
    
            th1.join();
            th2.join();
        }

        {
            let data = Arc::new(Mutex::new(0));
            let threads = vec![];

            for _ in 0..4 {
                let dataClone = Arc::clone(&data);
                let t = thread::spawn(|| {
                    let mut dataLock = dataClone.lock().unwrap();
                    *dataLock += 1;
                });
                thread.push(t);
            }
            for t in threads {
                t.join().unwrap();
            }
        }

        {
            let (sender, receiver) = mpsc::channal();
            let senderClon = sender.clone();
            let worker = thread::spawn(move || {
                senderClon.send("Hello").unwrap();
            });
            let data = receiver.recv().unwrap();
        }
    }

    // COUNTER has been created in every thread
    thread_local! {
        static COUTNER: std::cell::RefCell<u32> = std::cell::RefCell::new(10);
    }

    fn secondTest() {
        let th = thread::spawn(|| {
            COUNTER.with(|data| {
                let mut val = data.borrow_mut();
                *value *= i;
            });
        });
    }
}

/*----------------------------------*/

    /* File system */

{
    use std::fs;
    use std::path::Path;

    fn test() -> Result<(), std::io::Error> {
        fs::create_dir("test")?;
        fs::create_dir_all("hello/test")
        if !Path::new("test").exists() {
            fs::create_dir("test");
        }
    }

    fn secondTest() Result<(), std::io::Error> {
        File::create("text.txt");
        let file = File::open("text.txt");
        file.write_all(String::from("hello").as_bytes())?;

        let mut content = String::new();
        file.read_to_string(&mut content)?;

        let reader = BufReader::new(file);
        for line in reader.lines() {
            let line = line?;
            println!(line);
        }
    }
}

/*----------------------------------*/

    /* Tests */

    /*
        assert!(cond);
        assert!(cond, "error msg");
        assert_eq!(l, r);
        assert_eq!(l, r, "error msg");
        assert_ne!(l, r);
        assert_ne!(l, r, "error msg");

        #[cfg(test)] - only when cargo test
        #[cfg(test, feature = "linux")]
    */

/*----------------------------------*/

    /* Macros */

{
    #[proc_macro]
    fn macroFoo() {}

    fn test() {
        macroFoo!();
    }
}

/*----------------------------------*/