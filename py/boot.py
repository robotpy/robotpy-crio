class RollbackImporter:
    def __init__(self):
        "Creates an instance and installs as the global importer"
        self.previousModules = sys.modules.copy()
        
    def uninstall(self):
        newmodules = sys.modules.copy()
        for modname in newmodules.keys():
            if modname not in self.previousModules:
                # Force reload when modname next imported
                del(sys.modules[modname])

if __name__ == "__main__":
    import sys
    #print(sys.path)
    if "/py" not in sys.path:
        sys.path.insert(0, "/py")
    if "." not in sys.path:
        sys.path.insert(0, ".")

    # Bring in wpilib before starting rollback importer
    import wpilib

    rollback = RollbackImporter()
    try:
        from robot import run
        print("Running user code.")
        run()
    finally:
        rollback.uninstall()

