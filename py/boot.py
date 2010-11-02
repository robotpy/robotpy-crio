import sys

class RollbackImporter:
    def __init__(self):
        "Creates an instance and installs as the global importer"
        self.previousModules = sys.modules.copy()
        
    def uninstall(self):
        newmodules = sys.modules.copy()
        for modname in newmodules.keys():
            if modname not in self.previousModules:
                # Force reload when modname next imported
                del sys.modules[modname]

if __name__ == "__main__":
    #print(sys.path)
    if "/py" not in sys.path:
        sys.path.insert(0, "/py")
    if "." not in sys.path:
        sys.path.insert(0, ".")

    import traceback
    import gc
    import time

    while True:
        rollback = RollbackImporter()
        try:
            from robot import run
            print("Running user code.")
            run()
        except:
            print("Exception in user code:")
            print("-"*60)
            traceback.print_exc(file=sys.stdout)
            print("-"*60)
        finally:
            rollback.uninstall()
            gc.collect()
        print("User code ended; waiting 5 seconds before restart")
        time.sleep(5)

